#include "declaration.h"

void send_response(FILE * client, int code, const char * reason_phrase, const char * message_body){

}

void send_status(FILE * client, int code, const char *reason_phrase){
}

// Fonction qui renvoie le message de bienvenue
char * welcomeMessage(){
    char *message = "HTTP/1.1 200 OK\r\n"
        "Content-Length: 247\r\n"
        "\r\n"
        "*****************\r\n"
        "Bien le bonjour,\r\n"
        "Nous te souhaitons la bienvenue.\r\n"
        "Nous espérons que tu vas kiffer.\r\n"
        "Y'a pleins de fonctionnalités.\r\n"
        "Mais la flemme de te faire la liste.\r\n"
        "William et Benoit.\r\n"
        "La bise.\r\n"
        "Tu peux nous remercier.\r\n"
        "*************\r\n";
    //write(socket_client, message, strlen(message));
    return message;
}

// Fonction qui renvoie le message d'erreur 404
char * error404Message(){
    char *message = "HTTP/1.1 404 Not Found\r\n"
        "Connection: close\r\n"
        "Content-Length: 54\r\n"
        "\r\n"
        "Erreur 404 : Ressource non disponible ou inexistante\r\n";
    return message;
}

// Fonction qui renvoie le message d'erreur 400
char * badRequestMessage(){
    char * message = "HTTP/1.1 400 Bad Request\r\n"
        "Connection: close\r\n"
        "Content-Length: 17\r\n"
        "\r\n"
        "400 Bad request\r\n";
    return message;
}
