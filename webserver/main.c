#include "declaration.h"

int socket_serveur;

int main(void){
    socket_serveur = creationSocket();
    if(socket_serveur > 0){
        printf("Le serveur a bien été créé au port %d.\n", FINALPROTOCOL);
    }

    int erreur = initialiser_signaux();

    while(1){
        if(erreur != 0 ) {
            afficher_erreur(erreur);
            exit(1);
        }
        erreur = launchListenning(socket_serveur);
    }

}
