#include "declaration.h"

int attachementSocket(int socket_serveur);
int launchListenning(int socket_serveur);

int creationSocket(){
    int socket_serveur = socket(DOMAINEIP, TYPE, PROTOCOL);

    if (socket_serveur == -1) {
        perror("Erreur lors de la création du serveur. \n");
        return -1;
    }

    return attachementSocket(socket_serveur);
}

int attachementSocket(int socket_serveur){
    int optVal = 1;
    if(setsockopt(socket_serveur, SOL_SOCKET, SO_REUSEADDR, &optVal, sizeof(int)) == -1){
        perror("Erreur lors de l'identification par setsockopt.\n");
        return -2;
    }

    saddr.sin_family =  DOMAINEIP;
    saddr.sin_port = htons(FINALPROTOCOL);
    saddr.sin_addr.s_addr = INADDR_ANY;

    if(bind(socket_serveur, (struct sockaddr *)&saddr, sizeof(saddr)) == -1){
        perror("Erreur lors de l'attachement de la Socket. \n");
        return -3;
    }
    return launchListenning(socket_serveur);
}

int launchListenning(int socket_serveur){
    if(listen(socket_serveur, FINALPROTOCOL) == -1){
        perror("Erreur du lancement de l'écoute de connexion. \n");
        return -4;
    }
    return socket_serveur;
}
