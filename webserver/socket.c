#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

int socket_server;

socket_server = socket(AF_INET ,SOCK_STREAM ,0);
    if(socket_server == -1){
    /* traitement de l ’ erreur */
        perror("socket_server");
    }
/* Utilisation de la socket server */
