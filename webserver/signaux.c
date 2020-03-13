#include "declaration.h"

// Une fonction qui lit les lignes envoyées par le client
void skip_headers(FILE * client){
    char reception[1024];
    const char * one = "\r\n";
    const char * two = "\n";
    do {
        memset(reception, 0, sizeof(reception));
        fgets_or_exit(reception, 1024, client);
    }while(!strcmp(one,reception) && !strcmp(two, reception));
}

// Une fonction créée psk le sujet le demande
char * fgets_or_exit(char * buffer, int size, FILE * stream){
    while(fgets(buffer, size, stream) != NULL){
        return buffer;
    }
    exit(1);
}

// Récupère le contenu du fichier
char * get_file_content(char * buffer, int size, FILE * stream) {
    char * save = buffer;
    int idx = 0;
    char c;
    do {
        c = fgetc(stream);
        if ( c!=EOF ) {
            *buffer = c;
            ++buffer;
        }
        ++idx;
    }while(idx < size && c != EOF);
    return save;
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
int nettoyage_signaux(){

    struct sigaction sa;

    sa.sa_handler = traitement_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGCHLD, &sa, NULL) == -1){
        perror("Erreur de traitement des processus zombies");
        return -8;
    }
    return 0;
}

// Fonction qui initialise les signaux
int initialiser_signaux(){
    if(signal(SIGPIPE, SIG_IGN) == SIG_ERR){
        perror("TU AS ERREUR SIGNAL");
        return -7;
    }
    nettoyage_signaux();

    return 0;
}
