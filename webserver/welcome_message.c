#include "declaration.h"

//Fonction qui affiche le message d'accueil au client
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

// Affichage du signal reçu
void traitement_signal(int sig){
    pid_t pid;
    int status;

    while((pid = waitpid(-1, &status, WNOHANG)) > 0){
        printf("Child %d killed by sig %d \n", pid, sig);
    }

}

// Méthode de nettoyage des siganux zombies
void nettoyage_signaux(){

    struct sigaction sa;

    sa.sa_handler = traitement_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    printf("go");
    if (sigaction(SIGCHLD, &sa, NULL) == -1){
        perror("Erreur de traitement des processus zombies");
    }
}

// Fonction qui initialise les signaux
void initialiser_signaux(){
    if(signal(SIGPIPE, SIG_IGN) == SIG_ERR){
        perror("TU AS ERREUR SIGNAL");
    }
    printf("yo");
    nettoyage_signaux();
}
