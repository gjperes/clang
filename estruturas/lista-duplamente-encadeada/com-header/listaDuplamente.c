#include "listaDuplamente.h"
#include <stdlib.h>

Node cria_node() {
    Node *novo = NULL;

    novo = (Node *) malloc(sizeof(Node));
    if (!novo) {
        printf("Erro de alocação!");
        exit(1);
    }

    return novo;
}

void liberar_lista(Header *Lista) {
    if (Lista->primeiroNode != NULL) {
        Node *aux = NULL;
        while (Lista->primeiroNode != NULL) {
            aux = Lista->primeiroNode;
            Lista->primeiroNode = Lista->primeiroNode->prox;
            free(aux);
        }
        free(Lista->primeiroNode);
    }
}

int inserir_inicio_lista(Header *Lista, int dado) {
    Node *novo = cria_node();

    novo->dado = dado;
    novo->prox = Lista->primeiroNode;
    novo->ant = NULL;

    // Se não for o primeiro elemento da lista:
    if (Lista->primeiroNode != NULL) {
        (Lista->primeiroNode)->ant = novo;
    } else {
        Lista->ultimoNode = novo;
    }

    // A lista passa a apontar pra esse novo elemento
    Lista->primeiroNode = novo;
    Lista->tamanhoLista += 1;

    return 1;
}

int inserir_final_lista(Header *Lista, int dado) {
    Node *novo = cria_node();

    novo->dado = dado;
    novo->prox = NULL;
    novo->ant = Lista->ultimoNode;

    if(Lista->ultimoNode != NULL) {
        (Lista->ultimoNode)->prox = novo;
    } else {
        Lista->primeiroNode = novo;
    }

    Lista->ultimoNode = novo;
    Lista->tamanhoLista += 1;

    return 1;
}

int remover_inicio_lista(Header *Lista) {

}