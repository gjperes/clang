#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "joseph.h"

int main() {
    Header MinhaLista;
    char nomeSoldados[MAX_SOLDADOS][TAM_NOME];
    char soldadoInicialContagem[TAM_NOME];
    int n = 0;
    int i = 0;

    for(i = 0; i < 5; i++) {
        printf("Nome do %dº Soldado: ", i);
        scanf(" %c", nomeSoldados[i]);
    }

//    for (int j = 0; j < 5; j++) {
//        printf("%c\n", nomeSoldados[j][0]);
//    }

    printf("Número: ");
    scanf("%d", &n);

    printf("Nome do Soldado para iniciar a contagem: ");
    scanf(" %c", soldadoInicialContagem);

    // inicializaLista(&MinhaLista);

    return 0;
}