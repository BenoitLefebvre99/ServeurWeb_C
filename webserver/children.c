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
    //char c;
    FILE * recept = fdopen(socket_client, "a+");

    do {
        memset(reception, 0, sizeof(reception));
        while(fgets(reception, 1024, recept) != NULL){
            fprintf(recept, "\n<MonServeur>");
            fputs(reception, recept);
        }
        fflush(recept);
    }while(1);

    return 0;
}
