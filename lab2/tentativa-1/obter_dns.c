#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 500

int main(void) {

  setlocale(LC_ALL,"Portuguese");

  char in_url[MAX];
  struct hostent *endereco;
  struct in_addr addr;
 
  //pegamos entrada do usuario
  printf("digite um ip: ");
  fgets(in_url, sizeof(in_url), stdin);
  in_url[strlen(in_url)-1] = '\0';

  inet_aton(in_url, &addr);
  endereco = gethostbyaddr(&addr, sizeof(addr), AF_INET);

  printf("Host name: %s\n", endereco->h_name);
  return 0;
}