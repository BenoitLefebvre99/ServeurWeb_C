#include "declaration.h"

int launchChild(int socket_client){
    int pid = fork();

    if(pid){
        if(close(socket_client) == -1){
            perror("Erreur lors de la création du processus fils");
            return -6;
        }
        return 0;
    }

    welcomeMessage(socket_client);

    char reception[1024];
    int retour;

    do{
        memset(reception, 0, sizeof(reception));
        retour = read(socket_client, reception, sizeof(reception));
        if(retour == -1){
            perror("Erreur lors de la lecture");
            return -7;
        }
        else if(retour == 0 ){
            break;
        }
        printf("%s", reception);
    }while(1);

    return 0;
}