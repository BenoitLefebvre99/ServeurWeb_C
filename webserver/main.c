#include "declaration.h"

int socket_serveur;

int main(void){
    socket_serveur = creationSocket();

    int erreur = initialiser_signaux();

    while(1){
        erreur = launchListenning(socket_serveur);

        if(erreur != 0) {
            afficher_erreur(erreur);

        }
    }

}
