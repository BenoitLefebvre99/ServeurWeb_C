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

    char reception[1024];
    FILE * recept = fdopen(socket_client, "a+");
    memset(reception, 0, sizeof(reception));

    skip_headers(recept);

    fgets_or_exit(reception, 1024, recept);
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
    fflush(recept);

    return 0;
}
