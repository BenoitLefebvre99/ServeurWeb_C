#include "declaration.h"

// Une fonction créée psk le sujet le demande
char * fgets_or_exit(char * buffer, int size, FILE * stream){
    while(fgets(buffer, size, stream) != NULL){
        return buffer;
    }
    exit(1);
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
