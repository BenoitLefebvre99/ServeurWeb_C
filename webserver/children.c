#include "declaration.h"

int launchChild(int socket_client){
    int pid = fork();

    const char * GOOD_REQUEST = "GET / HTTP/1.1\r\n";
    const char * BAD_REQUEST_ANSWER = "HTTP/1.1 400 Bad Request\r\nConnection: close\r\nContent-Length: 17\r\n\r\n400 Bad request\r\n";
    const char * GOOD_REQUEST_ANSWER = welcomeMessage();

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
            //fprintf(recept, "\n<MonServeur>");
            //fputs(reception, recept);
            printf("%s", reception);
            if(strcmp(GOOD_REQUEST, reception)){
                fputs(BAD_REQUEST_ANSWER, recept);
                rupture = 2;
                break;
            }
            fputs(GOOD_REQUEST_ANSWER, recept);
            //printf("%ld", strlen(GOOD_REQUEST_ANSWER));
            rupture = 1 ;
            break;
        }
        fflush(recept);
    }while(!rupture);

    return 0;
}
