#include <stdio.h>
#define TAM 100

void convertelower(char *source) {
    char *s = source;

    while (*s) {
    // percorre de maneira linear o vetor de string, convertendo
        if ( (int)*s > 64 && (int)*s < 91 ) {
        // maiusculo para minusculo
            *s = ((int)*s + 32);
        }
        s++;
    }
}

int compara(char *txtA, char *txtB){
    const unsigned char *p1 = (const unsigned char *)txtA;
    const unsigned char *p2 = (const unsigned char *)txtB;
    unsigned char c1, c2;
    int resultado;

    do {
        c1 = (unsigned char) *p1++;
        c2 = (unsigned char) *p2++;

        if (c1 == '\0'){
            break;
        }

    } while(c1 == c2);

    resultado = c1 - c2;

    if (resultado > 0) {
        return 1;
    } else if (resultado < 0) {
        return -1;
    }
    return 0;
}

int main() {
    char textoA[TAM], textoB[TAM];

    scanf("%s\n%s", textoA, textoB);
    convertelower(textoA);
    convertelower(textoB);

    printf("%d\n", compara(textoA, textoB));
    
    return 0;
}