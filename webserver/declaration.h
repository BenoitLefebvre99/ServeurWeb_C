#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define DOMAINEIP AF_INET
#define TYPE SOCK_STREAM
#define PROTOCOL 0
#define FINALPROTOCOL 8080
#define LISTEATTENTE 10

struct sockaddr_in saddr;

int creationSocket();
