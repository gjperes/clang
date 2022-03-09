#include <stdio.h>
#include <stdlib.h>
#include "listaDinEncadeada.h"

struct Bloco {
    int dado;
    struct Bloco *prox;
};

void iniciaLista(Node **noInicial) {
    *noInicial = NULL;
}

Node *criaNode() {
    Node *novoNo;

    novoNo = (Node *) malloc(sizeof(Node));

    if (!novoNo) {
        printf("Impossível alocar, erro!\n");
        exit(1);
    }

    novoNo->prox = NULL;
    return novoNo;
}

void insereFinalLista(Node **noInicial, int num) {
    Node *novoNo = criaNode();
    Node *aux;

    novoNo->dado = num;

    if (*noInicial == NULL) {
        *noInicial = novoNo;
    } else {
        aux = *noInicial;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novoNo;
    }
}

void insereInicioLista(Node **noInicial, int num) {
    Node *novoNo = criaNode();

    novoNo->dado = num;
    novoNo->prox = *noInicial;
    *noInicial = novoNo;
}

int removeInicioLista(Node **noInicial, int *retorno) {
    Node *aux;

    if (*noInicial == NULL) return 0;

    aux = *noInicial;
    *retorno = (*noInicial)->dado;
    *noInicial = (*noInicial)->prox;

    free(aux);
    return 1;
}

void imprimirLista(Node *noInicial) {
    Node *aux;

    if (noInicial == NULL) {
        printf("\nLista vazia\n");
    } else {
        for (aux = noInicial; aux != NULL; aux = aux->prox) {
            printf("%d\n", aux->dado);
        }
    }
}