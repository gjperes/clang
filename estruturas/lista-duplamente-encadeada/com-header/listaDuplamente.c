#include "listaDuplamente.h"
#include <stdlib.h>

void iniciar_header(Header *Lista) {
    Lista->primeiroNode = NULL;
    Lista->ultimoNode = NULL;
    Lista->tamanhoLista = 0;
}

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
    if (Lista->tamanhoLista != 0) {
        // O antigo primeiro passa a ter como nó anterior o novo nó
        (Lista->primeiroNode)->ant = novo;
    } else {
        // No caso de ser o primeiro elemento, ele também é o último
        Lista->ultimoNode = novo;
    }

    // O início da lista passa a apontar para esse novo elemento inserido no início
    Lista->primeiroNode = novo;
    Lista->tamanhoLista += 1;

    return 1;
}

int inserir_final_lista(Header *Lista, int dado) {
    Node *novo = cria_node();

    novo->dado = dado;
    novo->prox = NULL;
    novo->ant = Lista->ultimoNode;

    // Se não for o primeiro elemento da lista:
    if(Lista->tamanhoLista != 0) {
        // O antigo último elemento passa a apontar para o novo nó
        (Lista->ultimoNode)->prox = novo;
    } else {
        // Caso seja o único elemento da lista, também é o primeiro
        Lista->primeiroNode = novo;
    }

    // O último nó aponta para esse novo elemento no final da lista
    Lista->ultimoNode = novo;
    Lista->tamanhoLista += 1;

    return 1;
}

int remover_inicio_lista(Header *Lista) {
    if (Lista->tamanhoLista == 0) return 0;

}