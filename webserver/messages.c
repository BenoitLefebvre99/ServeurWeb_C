#include "declaration.h"

// Fonction qui envoie la réponse au client
void send_response(FILE * client, int code, const char * reason_phrase, const char * message_body){
    send_status(client, code, reason_phrase);
    fprintf(client, "Content-Length: %lu\n", strlen(message_body));
    fprintf(client, "\r\n");
    fputs(message_body, client);
}

// Fonction qui envoie le statut au client
void send_status(FILE * client, int code, const char *reason_phrase){
    fprintf(client, "HTTP/1.1 %d %s \n", code, reason_phrase);
}

// Fonction qui renvoie le message de bienvenue
char * welcomeMessage(){
    char *message = "*****************\r\n"
        "Bien le bonjour,\r\n"
        "Nous te souhaitons la bienvenue.\r\n"
        "Nous espérons que tu vas kiffer.\r\n"
        "Y'a plein de fonctionnalités.\r\n"
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

//Fonction qui traite et affiche les erreurs
void afficher_erreur(int erreur) {
    switch(erreur) {
        case -1:
            printf(">>> Erreur %d : Erreur lors de la création de la socket\n", erreur);
            break;
        case -2:
            printf(">>> Erreur %d : Erreur lors de l'identification par setSockOpt\n", erreur);
            break;
        case -3:
            printf(">>> Erreur %d : Erreur lors de l'attachement de la Socket\n", erreur);
            break;
        case -4:
            printf(">>> Erreur %d : Erreur lors du paramètrage de l'écoute de connexion\n", erreur);
            break;
        case -5:
            printf(">>> Erreur %d : Erreur lors du lancements des écoutes\n", erreur);
            break;
        case -6:
            printf(">>> Erreur %d : Erreur lors de la création du processus fils\n", erreur);
            break;
        case -7:
            printf(">>> Erreur %d : Erreur lors de l'initialisation du signal\n", erreur);
            break;
        case -8:
            printf(">>> Erreur %d : Erreur lors du traitement des processus zombies\n", erreur);
            break;
        case -9:
            printf(">>> Erreur %d : Erreur lors de la lecture du fichier \n", erreur);
            break;
    }
}