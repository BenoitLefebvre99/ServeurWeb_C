#include "declaration.h"

int creationSocket(int domaine, int type, int protocol){
    int socket_serveur = socket(DOMAINEIP, AF_INET, PROTOCOL);
    if (socket_serveur == -1) {
        printf("Erreur lors de la création du serveur. \n")
        return -1;
    }
    return socket_serveur;
}