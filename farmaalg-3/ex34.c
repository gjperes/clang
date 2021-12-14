#include <stdio.h>
#define TAM 100

int mystrchr(char *frase, char *simbolo){
    char *f = frase;
    char *s = simbolo;

    while(*f) {

        if(*f == *s){
            // retorna a posição de encontro
            return (int)(f - frase); 
        }

        f++;
    }

    // caso não consiga retorno
    return (-1);
}

int main(){
    char texto[TAM];
    char simbolo[1];

    fgets(texto, TAM, stdin);
    scanf("%c", simbolo);

    printf("%d\n", mystrchr(texto, simbolo));

    return 0;
}