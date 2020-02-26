//Déclaration des bibliothèques
#include <stdio.h>
#include <stdlib.h>
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
char * welcomeMessage();
char * error404Message();
char * badRequestMessage();
void initialiser_signaux();
int launchListenning(int socket_serveur);
int launchChild(int socket_client);
void nettoyage_signaux();
char * fgets_or_exit(char * buffer, int size, FILE *stream);
