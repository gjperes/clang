#include <stdio.h>
#define TAM 128

int mystrlen(char *source){
    char *s = source;

    while(*s)
        s++;

    return (s - source);
}

void sufixo(char *source, int len){
    char *s;
    
    for (int aux=0; aux < len; aux++) {
        s = (source + aux);
        while(*s) {
            printf("%c", *s);
            s++;
        }
        printf("\n");
    }
}

int main(){
    char texto[TAM];

    scanf("%s", texto);
    sufixo(texto, mystrlen(texto));

    return 0;
}