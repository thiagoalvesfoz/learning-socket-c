#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

//imports
#include "def/error.h"

#define PORT 8080
#define MAXDATASIZE 500
#define BACKLOG 5

int main() {
	char userName[50];
	char *bufferRcv, *_bufferRcv, *msgContent, *buffer_out;

	struct sockaddr_in local, client;
	int localSocket, clientSocket;

	system("clear");
  printf("Servidor iniciado\n");

  //Configurações do socket local
	if((localSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
		errorSocket();
		
	//Configuração do socket local
	local.sin_family = AF_INET; 
	local.sin_port = htons(PORT);  	
	local.sin_addr.s_addr = INADDR_ANY;
	memset(local.sin_zero, 0, 8);

  //Associação da porta
	if(bind(localSocket, (struct sockaddr *)&local, sizeof(local)) == -1)
		errorBind();
	
	//Inicio da escuta
	if(listen (localSocket, BACKLOG) == -1)
		errorListen();

  //Agurda um processo conectars-se
  int client_len = sizeof(struct sockaddr_in);
  clientSocket = accept(localSocket, (struct sockaddr *)&client, &client_len);

  int fluxo = 0;
  while(!fluxo) {

    // limpa os buffers
    memset(_bufferRcv, 0, MAXDATASIZE);
    memset(bufferRcv, 0, MAXDATASIZE);

    //Recebe uma mensagem e guarda o estado de atividade do cliente
    int isActive = recv(clientSocket, bufferRcv, MAXDATASIZE,  0);
    strcpy(_bufferRcv, bufferRcv);

    if (isActive)	 {
        printf("message: %s", _bufferRcv);
    }

    printf("send: ");
    fgets(buffer_out, MAXDATASIZE, stdin);
    send(clientSocket, buffer_out, strlen(buffer_out), 0);

  }

  close(clientSocket);
  close(localSocket);
  return EXIT_SUCCESS;
}