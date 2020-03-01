#include "declaration.h"

void send_response(FILE * client, int code, const char * reason_phrase, const char * message_body){
    send_status(client, code, reason_phrase);
    fprintf(client, "Content-Length: %lu\n", strlen(message_body));
    fprintf(client, "\r\n");
    fputs(message_body, client);
}

void send_status(FILE * client, int code, const char *reason_phrase){
    fprintf(client, "HTTP/1.1 %d %s \n", code, reason_phrase);
}

// Fonction qui renvoie le message de bienvenue
char * welcomeMessage(){
    char *message = "*****************\r\n"
        "Bien le bonjour,\r\n"
        "Nous te souhaitons la bienvenue.\r\n"
        "Nous espérons que tu vas kiffer.\r\n"
        "Y'a pleins de fonctionnalités.\r\n"
        "Mais la flemme de te faire la liste.\r\n"
        "William et Benoit.\r\n"
        "La bise.\r\n"
        "Tu peux nous remercier.\r\n"
        "*************\r\n";
    return message;
}

// Fonction qui renvoie le message d'erreur 404
char * error404Message(){
    char *message = "Erreur 404 : Ressource non disponible ou inexistante\r\n";
    return message;
}

// Fonction qui renvoie le message d'erreur 400
char * badRequestMessage(){
    char * message = "400 Bad request\r\n";
    return message;
}
