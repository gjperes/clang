#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "joseph.h"

#define MAX_SOLDADOS 5;

int main() {
    Cabecalho MinhaLista;
    char nomeSoldados[MAX_SOLDADOS][TAM_NOME];
    char soldadoInicialContagem[TAM_NOME];
    int n = 0;
    
    for(int i = 0; i < MAX_SOLDADOS; i++) {
        scanf("%c", nomeSoldados[i]);
    }

    scanf("%d", &n);
    scanf("%s", &soldadoInicialContagem);

    // inicializaLista(&MinhaLista);

    return 0;
}
