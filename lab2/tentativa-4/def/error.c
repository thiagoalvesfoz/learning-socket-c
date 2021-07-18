#include <error.h>
#include <stdlib.h>

void errorSocket() {
  perror("Erro ao criar socket");
  exit(1);
}

void errorConnection() {
  perror("Erro durante a conexão");
	exit(1);
}

void errorReceiver() {
  perror("Erro ao se conectar ao servidor, tente mais tarde");
	exit(1);
}

void errorBind(){
	perror("Erro ao associar porta");
	exit(1);
}

void errorListen() {
  perror("Erro ao iniciar a escuta");
	exit(1);
}