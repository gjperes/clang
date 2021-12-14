#include <stdio.h>
#define TAM 128

int mystrlen(char *source){
    char *s = source;

    while(*s)
        s++;

    return (s - source);
}

void prefixo(char *source, int len){
    char *s;
    
    for (int i=1; i <= len; i++){
        s = source;
        for (int aux=0; aux < i; aux++){
            printf("%c", *s);
            s++;
        }
        printf("\n");
    }
}

int main(){
    char texto[TAM];

    scanf("%s", texto);
    prefixo(texto, mystrlen(texto));

    return 0;
}
