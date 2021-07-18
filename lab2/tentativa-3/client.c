#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define PORT 8080
#define BUFFER_LENGTH 4096
#define SERVER_ADDR "127.0.0.1"

#define ERROR -1
#define MAX 100
char username[MAX];

int create_socket() {

    struct sockaddr_in server;
    int serverfd;

    server.sin_family = AF_INET;                        // Família IP v4
    server.sin_port = htons(PORT);                      // Porta que irá se conectar
    server.sin_addr.s_addr = inet_addr(SERVER_ADDR);    // seila
    memset(server.sin_zero, 0x0, 8);                    // Seila x2

    ///////////////////////////////////////////////////////////////////////
    // Criando o socket
    if ((serverfd = socket(AF_INET , SOCK_STREAM , 0)) == ERROR) {
        perror("Error on client socket creation. ");
        return ERROR;
    } else {
        fprintf(stdout, "Client socket criado com descriptor: %d\n", serverfd);
    }
    
    ///////////////////////////////////////////////////////////////////////   
    // Tentando uma conexão com o server
    if (connect(serverfd, (struct sockaddr*) &server, sizeof(server)) == ERROR) {
        perror("Can't connect to server");
        return ERROR;
    }

    return serverfd;
}


int main(int argc, char *argv[]) {

    int serverfd;    
    if((serverfd = create_socket()) == ERROR) {
        exit(EXIT_FAILURE);
    }

    // DEFININDO NOME DE USUÁRIO
    memset(username, 0x0, MAX);
    fprintf(stdout, "\nEscolha um nome de usuario: ");
    fgets(username, MAX, stdin);
    fprintf(stdout, "Nome de usuário: %s\n", username);
    send(serverfd, username, strlen(username), 0);
    //////////////////////////////////////////////////////

    int message_len;
    char buffer_in[BUFFER_LENGTH];
    char buffer_out[BUFFER_LENGTH];

    while(1) {

        memset(buffer_in, 0x0, BUFFER_LENGTH);
        memset(buffer_out, 0x0, BUFFER_LENGTH);

        fprintf(stdout, "send: ");
        fgets(buffer_out, BUFFER_LENGTH, stdin);
        send(serverfd, buffer_out, strlen(buffer_out), 0);

        if(strcmp(buffer_in, "exit\n") == 0 || strcmp(buffer_out, "exit\n") == 0) {     
            break;
        }

    }


    close(serverfd);
    fprintf(stdout, "\nChat Encerrado\n");
    return EXIT_SUCCESS;
}