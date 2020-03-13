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

    printf("\n");
    printf("\n");

    printf(">> %s\n", reception);

    http_request requete;

    if(parse_http_request(reception, &requete) == 0) {
        send_response(recept, 400, "Bad Request", badRequestMessage());
        printf("Erreur 400 : Mauvaise requète\n");
    }
    else if(requete.method == HTTP_UNSUPPORTED) {
        send_response(recept, 405, "Method Not Allowed", "Method Not Allowed\r\n");
        printf("Erreur 405 : Version HTTP non supportée.\n");
    }
    else if(strstr(requete.target, "../") != NULL){
        send_response(recept, 403, "Access Forbidden", "L'accès à l'adresse demandée est refusé.\r\n");
        printf("Erreur 403 : Accès à la ressource refusé.\n");
    }
    else {
        FILE * end = check_and_open(rewrite_target(requete.target), "../www");
        if(end == NULL) {
            send_response(recept, 404, "Not Found", error404Message());
            printf("Erreur 404 : Ressource introuvable\n");
        } else {
            /*char content[1024];
            memset(content, 0, sizeof(content));
            get_file_content(content, sizeof(content), end);
            printf("Envoie de la page www%s\n", requete.target);
            send_response(recept, 200, "OK", content);*/
            struct stat st;
            if(fstat(fileno(end), &st) == -1) {
                afficher_erreur(-9);
                exit(1);
            }
            send_status(recept, 200, "OK");
            fprintf(recept, "Content-Length: %lu\n", st.st_size);
            fprintf(recept, "\r\n");
            copy(end, recept);
        }
    }
    fflush(recept);
    fclose(recept);
    exit(0);
    return 0;
}
