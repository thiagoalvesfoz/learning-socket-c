#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <regex.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 500

int regex(char *regx_expr, char *str) {
  
  regex_t regex;
  int result;

  if ((regcomp(&regex, regx_expr, 0)) == 1) {
    fprintf(stderr, "Could not compile regex\n");
    exit(1);
  }

  result = !regexec(&regex, str, 0, NULL, 0);
  regfree(&regex);
  
  return result;
}

char* resolve_url(char *link) {

  char *expression = malloc(25*sizeof(char));

  if (regex("^http.", link)) {
    strcpy(expression, regex("https", link) ? "https://" : "http://");
  } else {
    strcpy(expression, "");
  }

  strcat(expression, "%99[^/]/%99[^\n]");
  return expression;
}

int main() {  

  setlocale(LC_ALL,"Portuguese");
  char host[MAX], page[MAX], keyboard_input[MAX];
  
  // Obter entrada do usuario
  printf("digite um link: ");
  fgets(keyboard_input, sizeof(keyboard_input), stdin);
  keyboard_input[strlen(keyboard_input)-1] = '\0';
  printf("\n");

  // Extrair domínio e páginas da url
  sscanf(keyboard_input, resolve_url(keyboard_input), host, page);
  printf("Domain = \"%s\"\n", host); 
  printf("Page = \"%s\"\n\n", page);

  // Tratando antes de enviar. 
  // Ex: GET /index.html HTTP/1.1\nHost: www.site.com\t \n\n
  strcat(page," HTTP/1.1\nHost: ");
  strcat(page,host); 
  strcat(page,"\t \n\n");


  // struct do netdb para converter host para ip
  struct hostent *ip;
  char *url;
  char getpage[MAX]="GET /";

  // função da lib netdb.h para converter nosso host para IP
  ip = gethostbyname(host);
  url= inet_ntoa(*(struct in_addr *) ip->h_addr);
  strcat(getpage, page);
  printf("%s",getpage);

  return 0;
}