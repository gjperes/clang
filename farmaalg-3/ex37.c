#include <stdio.h>
#define TAM 255

void inverteCaixa(char *source) {
    char *s = source;

    while (*s) {
    // percorre de maneira linear o vetor de string, convertendo
        if ( (int)*s > 64 && (int)*s < 91 ) {
        // maiusculo to min
            *s = ((int)*s + 32);
        }
        else if ( (int)*s > 96 && (int)*s < 123 ) {
        // maiusculo to min
            *s = ((int)*s - 32);
        }
        // após validar, incrementa ponteiro
        s++;
    }
}

int main() {
    char texto[TAM];

    fgets(texto, TAM, stdin);
    inverteCaixa(texto);

    printf("%s", texto);
    
    return 0;
}