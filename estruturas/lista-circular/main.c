#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "joseph.h"

int main() {
    Node *soldados = NULL;

    int numeroSorteado = 5;
    char nomesSoldados = {"ABCDEFGHIJ"};
    char soldadoInicial[1];

    // scanf("%d",&numeroSorteado);
    scanf("%c", soldadoInicial);

    criarListaSoldados(&nomesSoldados, &soldados);
    definirSoldado(&soldados, soldadoInicial, numeroSorteado);
    return 0;
}
