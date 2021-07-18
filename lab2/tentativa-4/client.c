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
#define SERVER_ADDR "127.0.0.1"

#define MAXDATASIZE 500
#define BACKLOG 5

int main() {
    char *bufferRcv, *_bufferRcv, *msgContent, *buffer_out;
	  struct sockaddr_in server;
    int serverfd;

    server.sin_family = AF_INET;                        // Família IP v4
    server.sin_port = htons(PORT);                      // Porta que irá se conectar
    server.sin_addr.s_addr = inet_addr(SERVER_ADDR);    // seila
    memset(server.sin_zero, 0, 8);                      // Seila x2

    ///////////////////////////////////////////////////////////////////////
    // Cria um socket
    if ((serverfd = socket(AF_INET , SOCK_STREAM , 0)) == -1) {
        errorSocket();
    } 

    ///////////////////////////////////////////////////////////////////////   
    // Tentando uma conexão com o server
    if (connect(serverfd, (struct sockaddr*) &server, sizeof(server)) == -1) {
        errorConnection();
    }

    
    int message_len;
    char buffer_in[MAXDATASIZE];
    char buffer_out[MAXDATASIZE];

    while(1) {

        memset(buffer_in, 0x0, MAXDATASIZE);
        memset(buffer_out, 0x0, MAXDATASIZE);

        //Recebe uma mensagem e guarda o estado de atividade do cliente
        int isActive = recv(serverfd, bufferRcv, MAXDATASIZE,  0);
        strcpy(_bufferRcv, bufferRcv);

        if (isActive)	 {
            printf("message: %s", _bufferRcv);
        }

        fprintf(stdout, "send: ");
        fgets(buffer_out, MAXDATASIZE, stdin);
        send(serverfd, buffer_out, strlen(buffer_out), 0);

        if(strcmp(buffer_in, "exit\n") == 0 || strcmp(buffer_out, "exit\n") == 0) {     
            break;
        }

    }

  close(serverfd);
  return EXIT_SUCCESS;
}