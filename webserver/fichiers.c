#include "declaration.h"

char * rewrite_target(char * target) {
    int idx = charAt(target, '?');
    char * save = target;
    if(idx == -1) {
        return target;
    }
    save = save + idx;
    *save = '\0';
    return target ;
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
    if (file == NULL) {
        exit(1);
    }
    return file;
}
/*int get_file_size(int fd) {
    return fd;
}
int copy(FILE * in, FILE * out ){
    return 0;
*/