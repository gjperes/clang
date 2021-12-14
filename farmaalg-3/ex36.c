#include <stdio.h>
#define TAM 128

void espelho(char *source){
    char *s = source;
    int aux;

    while(*s) // coloca o ponteiro no fim da string
        s++;

    do {
        s--; // vem primeiro para remover o \0 , e também exibir o primeiro char
        printf("%c", *s);
    } while (s != source);

    printf("\n");
}

int main(){
    char texto[TAM];

    scanf("%s", texto);
    espelho(texto);

    return 0;    
}