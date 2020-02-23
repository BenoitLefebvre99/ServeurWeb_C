#include "declaration.h"

int launchChild(int socket_client){
    int pid = fork();

    const char * GOOD_REQUEST = "GET / HTTP/1.1\r\n";
    const char * BAD_REQUEST = "HTTP/1.1 400 Bad Request\r\nConnection: close\r\nContent-Length: 17\r\n\r\n400 Bas request\r\n";

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
            //fprintf(recept, "\n<MonServeur>");
            //fputs(reception, recept);
            printf("%s", reception);
            if(!strcmp(GOOD_REQUEST, reception)){
                fputs(BAD_REQUEST, recept);
            }
        }
        fflush(recept);
    }while(1);

    return 0;
}
