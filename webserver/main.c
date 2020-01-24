#include "declaration.h"

const int DOMAINEIP = AF_INET;
const int TYPE = SOCK_STREAM;
const int PROTOCOL = 0;

int socket_serveur;

int main(void){
    socket_serveur = creationSocket(DOMAINEIP,TYPE, PROTOCOL);
    if(socket_serveur != -1){
        printf("Le serveur a bien été créé \n");
    }
}
