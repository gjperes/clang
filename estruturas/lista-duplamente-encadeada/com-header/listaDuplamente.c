#include "listaDuplamente.h"
#include <stdlib.h>

Node criaNode() {
    Node *novo = NULL;

    novo = (Node *) malloc(sizeof(Node));
    if (!novo) {
        printf("Erro de alocação!");
        exit(1);
    }

    return novo;
}

void liberarLista(Header *Lista) {
    if (Lista->primeiroNode != NULL) {
        Node aux = NULL;
        while (Lista->primeiroNode != NULL) {
            aux = Lista->primeiroNode;
            Lista->primeiroNode = Lista->primeiroNode->prox;
            free(aux);
        }
        free(Lista->primeiroNode);
    }
}