#include "declaration.h"

const DOMAINEIP = AF_INET;
const TYPE = SOCK_STREAM;
const PROTOCOL = 8080;

int socket_serveur;

int main(int argc, char **argv){
    socket_serveur = creationSocket(DOMAINEIP,TYPE, PROTOCOL);
    if(socket_serveur != -1){
        printf("Le serveur a bien été créé \n")
    }
}
