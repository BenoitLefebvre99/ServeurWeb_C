#include "declaration.h"

int launchChild(int socket_client){
    int pid = fork();

    if(pid){
        if(close(socket_client) == -1){
            perror("Erreur lors de la création du processus fils");
            return -6;
        }
    }
    else {
        welcomeMessage(socket_client);
    }

    return 0;
}