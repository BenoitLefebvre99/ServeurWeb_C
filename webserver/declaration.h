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
#include <sys/stat.h>
#include <time.h>

#include "socket.h"
#include "http_parse.h"

//Déclaration des constantes
#define DOMAINEIP AF_INET
#define TYPE SOCK_STREAM
#define PROTOCOL 0
#define FINALPROTOCOL 8080
#define LISTEATTENTE 10

//déclaration des fonctions externes 'public'
int creationSocket();
char * welcomeMessage();
char * error404Message();
char * badRequestMessage();
int initialiser_signaux();
int launchListenning(int socket_serveur);
int launchChild(int socket_client);
int nettoyage_signaux();
char * fgets_or_exit(char * buffer, int size, FILE *stream);
void skip_headers(FILE *client);
void send_status(FILE * client, int code, const char * reason_phrase);
void send_response(FILE * client, int code, const char * reason_phrase, const char * message_body);
char * rewrite_target(char * target);
FILE * check_and_open(const char * target, const char * document_root);
int get_file_size(int fd);
int copy(FILE * in, FILE * out);
int charAt(char * str, char c);
char * get_file_content(char * buffer, int size, FILE * stream);
int is_root(char * target);
char * adapt_target(char * buffer);
void afficher_erreur(int erreur);