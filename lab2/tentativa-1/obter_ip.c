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
  printf("digite um link: ");
  fgets(in_url, sizeof(in_url), stdin);
  in_url[strlen(in_url)-1] = '\0';

  // get the addresses 
  endereco = gethostbyname(in_url);

  // print information about this host:
  printf("\nO nome oficial é: %s\n", endereco->h_name);
  printf("\nEndereço IP: %s\n", inet_ntoa(*(struct in_addr*)endereco->h_addr));
  
  struct in_addr **lista_enderecos = (struct in_addr **) endereco->h_addr_list;
  
  printf("\nTodos os endereços IPs:\n");

  for(int i = 0; lista_enderecos[i] != NULL; i++) {
      printf("IP %d --> %s\n", i+1, inet_ntoa(*lista_enderecos[i]));
  }

  printf("\n");
  return 0;
}