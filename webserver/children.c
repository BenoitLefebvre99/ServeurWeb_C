#include "declaration.h"

int launchChild(int socket_client){
    int pid = fork();

    const char * GOOD_REQUEST = "GET / HTTP/1.1\r\n";
    const char * NOT_FOUND_REQUEST = "GET /inexistant HTTP/1.1\r\n";

    char * ANSWER;

    if(pid){
        if(close(socket_client) == -1){
            perror("Erreur lors de la création du processus fils");
            return -6;
        }
        return 0;
    }

    //printf("%lu", strlen(GOOD_REQUEST_ANSWER));
    char reception[1024];
    int rupture = 0;
    //char c;
    FILE * recept = fdopen(socket_client, "a+");

    do {
        memset(reception, 0, sizeof(reception));
        while(fgets(reception, 1024, recept) != NULL){
            printf("%s", reception);
            if(!strcmp(GOOD_REQUEST, reception)){
                ANSWER = welcomeMessage();
            }
            else if(!strcmp(NOT_FOUND_REQUEST,reception)){
                ANSWER = error404Message();
            }
            else {
                ANSWER = badRequestMessage();

            }
            fputs(ANSWER, recept);
            rupture = 1 ;
        }
        fflush(recept);
    }while(!rupture);

    return 0;
}
