#include "declaration.h"

int creationSocket(int domaine, int type, int protocol){
    int socket_serveur = socket(domaine, type, protocol);
    if (socket_serveur == -1) {
        perror("Erreur lors de la création du serveur. \n");
        return -1;
    }
    if(bind(socket_serveur, (struct sockaddr *)&saddr, sizeof(saddr)) == -1){
        perror("Erreur lors de l'attachement de la Socket. \n");
        return -2;
    }
    return socket_serveur;
}
