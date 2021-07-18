#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> 

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_LENGTH 4096
#define MAX_CONNECTIONS 2

#define ERROR -1
#define MAX 100
char USER[MAX];

const char CLOSE[25] = "Server disconnected\n\0";

void init_chat(int serverfd) {

    struct sockaddr_in client;
    socklen_t client_len = sizeof(client);
    int clientfd;

    int message_len;
    char buffer_in[BUFFER_LENGTH];
    char buffer_out[BUFFER_LENGTH];

    fprintf(stdout, "\nAguardando por conexões...\n");
    if ((clientfd=accept(serverfd, (struct sockaddr *) &client, &client_len)) == -1) {
        perror("Accept error:");
        exit(EXIT_FAILURE);
    }

    if((message_len = recv(clientfd, buffer_in, BUFFER_LENGTH, 0)) > 0) {
        buffer_in[message_len - 1] = '\0';
        strcpy(USER, buffer_in);
        printf("%s is connected.\n", buffer_in);
    }

    while(1) {        

        // limpa os buffers
        memset(buffer_in, 0x0, BUFFER_LENGTH);
        memset(buffer_out, 0x0, BUFFER_LENGTH);

        // aguarda mensagens (bloqueante)
        if((message_len = recv(clientfd, buffer_in, BUFFER_LENGTH, 0)) > 0) {
            printf("%s: %s", USER, buffer_in);
        }

        if(strcmp(buffer_in, "exit\n") == 0 || strcmp(buffer_out, "exit\n") == 0) {
            send(clientfd, CLOSE, strlen(buffer_out), 0);
            printf("%s", CLOSE);
            break;
        }
    };

    close(clientfd);
}

int create_socket() {

    struct sockaddr_in server;
    int serverfd;
    
    server.sin_family = AF_LOCAL;                    // Familia IP v4
    server.sin_port = htons(PORT);                   // Porta que será utilizada
    server.sin_addr.s_addr = htonl(INADDR_ANY);     
    memset(server.sin_zero, 0x0, 8);                


    ///////////////////////////////////////////////////////////////////////
    // Cria um socket
    if ((serverfd = socket(AF_INET , SOCK_STREAM , 0)) == ERROR) {
        perror("Could not create socket. ");
        return ERROR;
    } else {
        fprintf(stdout, "Server socket criado com descriptor: %d\n", serverfd);
    }

    ///////////////////////////////////////////////////////////////////////    
    // Cria um bind para o socket
    if(bind(serverfd, (struct sockaddr*) &server, sizeof(server)) == ERROR) {
        perror("Socket bind error:");
        return ERROR;
    }

    ///////////////////////////////////////////////////////////////////////
    // Aguarda conexão com os clientes
    if(listen(serverfd, MAX_CONNECTIONS) == ERROR) {
        perror("Listen error:");
        return ERROR;
    }

    return serverfd;
}

int main(int argc , char *argv[]) {

    int serverfd; // descriptor aqui
    if((serverfd = create_socket()) == ERROR) {
        exit(EXIT_FAILURE);
    }
    
    init_chat(serverfd);
    close(serverfd);

    printf("Connection closed\n\n");
    return EXIT_SUCCESS;
}
