#include "declaration.h"

//Déclaration des fonctions internes
int attachementSocket(int socket_serveur);
int setListenning(int socket_serveur);

//Fonction juste pour faire le lien avec le sujet
int creer_serveur(){
    return creationSocket();
}

//Fonction qui génère une socket
int creationSocket(){
    int socket_serveur = socket(DOMAINEIP, TYPE, PROTOCOL);

    if (socket_serveur == -1) {
        perror("Erreur lors de la création du serveur. \n");
        return -1;
    }

    return attachementSocket(socket_serveur);
}

//Fonction qui gère l'attachement de la Socket
int attachementSocket(int socket_serveur){
    //Activation des options de réutilisation
    int optVal = 1;
    if(setsockopt(socket_serveur, SOL_SOCKET, SO_REUSEADDR, &optVal, sizeof(int)) == -1){
        perror("Erreur lors de l'identification par setsockopt.\n");
        return -2;
    }

    struct sockaddr_in saddr;

    saddr.sin_family =  DOMAINEIP;
    saddr.sin_port = htons(FINALPROTOCOL);
    saddr.sin_addr.s_addr = INADDR_ANY;

    //Attribution de la socket aux interfaces réseaux
    if(bind(socket_serveur, (struct sockaddr *)&saddr, sizeof(saddr)) == -1){
        perror("Erreur lors de l'attachement de la Socket. \n");
        return -3;
    }
    return setListenning(socket_serveur);
}
//Paramètrages des écoutes de connexion
int setListenning(int socket_serveur){
    if(listen(socket_serveur, LISTEATTENTE) == -1){
        perror("Erreur lors du paramétrage de l'écoute de connexion. \n");
        return -4;
    }
    return launchListenning(socket_serveur);
}
//Lancement des écoutes de connexion
int launchListenning(int socket_serveur){

    int socket_client = accept(socket_serveur, NULL, NULL);
    if( socket_client == -1){
        perror("Erreur du lancement des écoutes. \n");
        return -5;
    }

    welcomeMessage(socket_client);

    return socket_serveur;
}
