#include "declaration.h"

char * rewrite_target(char * target) {
    int idx = charAt(target, '?');
    char * save = target;
    if() {

    }
    if(idx == -1) {
        return target;
    }
    save = save + idx;
    *save = '\0';
    return target ;
}
int is_root(char * target) {
    return strcmp(target, "/");
}
int charAt(char * str, char c) {
    int res = 0;
    if(strchr(str, c) == NULL){
        return -1;
    }
    do {
        ++res;
        ++str;
    } while(*str != c && *str != '\0');
    return res;
}
FILE * check_and_open(const char * target, const char * document_root){
    FILE * file = NULL;
    char link[1024];
    memset(link, 0, sizeof(link));
    strcat(link, document_root);
    strcat(link, target);
    file = fopen(link, "r");
    return file;
}
int get_file_size(int fd) {
    int res = 0;
    char c;
    FILE * file = fdopen(fd, "r");
    if (file == NULL) {
        return -1;
    }
    while((c=fgetc(file))!=EOF) {
        res++;
    }
    return res;
}
int copy(FILE * in, FILE * out ){
    char str[1024];
    char * string;
    memset(str, 0, sizeof(str));
    while(1) {
        string = fgets_or_exit(str, sizeof(str), in);
        fprintf(out, "%s", string);
    }
    return 0;
}
