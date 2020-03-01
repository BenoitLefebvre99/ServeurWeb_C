#include "declaration.h"

int launchChild(int socket_client){
    // Création d'un processus fils
    int pid = fork();
    if(pid){
        if(close(socket_client) == -1){
            perror("Erreur lors de la création du processus fils");
            return -6;
        }
        return 0;
    }

    char reception[1024];
    memset(reception, 0, sizeof(reception));

    FILE * recept = fdopen(socket_client, "a+");

    //skip_headers(recept);

    fgets_or_exit(reception, 1024, recept);
    printf("%s", reception);

    http_request requete;

    if(parse_http_request(reception, &requete) == 0) {
        send_response(recept, 400, "Bad Request", badRequestMessage());
    }
    else if(strcmp(requete.target, "/") == 0) {
        send_response(recept, 200, "OK", welcomeMessage());
    }
    else if(requete.method == HTTP_UNSUPPORTED) {
        send_response(recept, 405, "Method Not Allowed", "Method Not Allowed\r\n");
    }
    else {
        send_response(recept, 404, "Not Found", error404Message());
    }
    fflush(recept);

    return 0;
}
