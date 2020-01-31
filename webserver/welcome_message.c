#include "declaration.h"

//Fonction qui affiche le message d'accueil au client
void welcomeMessage(int socket_serveur){
    const char *message = "*****************\n Bien le bonjour, \n Nous te souhaitons la bienvenue. \n Nous espérons que tu vas kiffer.\n Y'a pleins de fonctionnalités.\n Mais la flemme de te faire la liste. \n William et Benoit. \n La bise. \n Tu peux nous remercier. \n *************\n";
    write(socket_serveur, message, strlen(message));
}
