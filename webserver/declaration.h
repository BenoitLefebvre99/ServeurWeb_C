//Déclaration des bibliothèques
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "socket.h"

//Déclaration des constantes
#define DOMAINEIP AF_INET
#define TYPE SOCK_STREAM
#define PROTOCOL 0
#define FINALPROTOCOL 8080
#define LISTEATTENTE 10
#define NOM_SERVEUR "MonServeur"

//déclaration des fonctions externes 'public'
int creationSocket();
void welcomeMessage(int socket_serveur);
void initialiser_signaux();
int launchListenning(int socket_serveur);
int launchChild(int socket_client);
void nettoyage_signaux();
