// implementar mystrstr

#include <stdio.h>
#define TAM 128

int mystrlen(char *txt) {
    char *t = txt;

    while(*t)
        t++;

    return (int)(t - txt);
}

int mystrstr(char *source, char *cmp, int lencmp){
    char *s = source, *c = cmp, *aux;

    while( *s ) {

        if(*s == *c) {
        // se encontrar o primeiro char igual compara o restante dos chars
            aux = s; // seta o pnt aux na pos inicial

            do {
                aux++;
                c++;
            } while((*c == *aux) && (*c != '\0'));

            if((int)(c - cmp) == lencmp)
                return (int)(s - source);

        }

        s++;
        c = cmp; // seta novamente no início
    }

    return (-1);
}

int main(){
    char texto[TAM], substring[TAM];

    scanf("%s", substring);
    scanf("%s", texto);

    printf("%d\n", mystrstr(texto, substring, mystrlen(substring)));

    return 0;
}