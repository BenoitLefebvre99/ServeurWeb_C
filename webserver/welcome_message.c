#include "declaration.h"

//Fonction qui affiche le message d'accueil au client
void welcomeMessage(int socket_client){
    const char *message = "*****************\n Bien le bonjour, \n Nous te souhaitons la bienvenue. \n Nous espérons que tu vas kiffer.\n Y'a pleins de fonctionnalités.\n Mais la flemme de te faire la liste. \n William et Benoit. \n La bise. \n Tu peux nous remercier. \n *************\n";
    write(socket_client, message, strlen(message));
}

// Fonction qui initialise les signaux
void initialiser_signaux(){
    if(signal(SIGPIPE, SIG_IGN) == SIG_ERR){
        perror("TU AS ERREUR SIGNAL");
    }
}
