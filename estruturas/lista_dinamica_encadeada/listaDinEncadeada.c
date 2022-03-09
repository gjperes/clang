#include <stdio.h>
#include <stdlib.h>
#include "listaDinEncadeada.h"

struct Bloco {
    int dado;
    struct Bloco *prox;
};

void iniciarLista(Node **noInicial) {
    *noInicial = NULL;
}

void liberarLista(Node **noInicial) {
    Node *aux;

    while (*noInicial != NULL) {
        aux = *noInicial;
        *noInicial = (*noInicial)->prox;
        free(aux);
    }
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

void inserirFinalLista(Node **noInicial, int num) {
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

void inserirInicioLista(Node **noInicial, int num) {
    Node *novoNo = criaNode();

    novoNo->dado = num;
    novoNo->prox = *noInicial;
    *noInicial = novoNo;
}

int removerInicioLista(Node **noInicial, int *retorno) {
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

int verificarTamanhoLista(Node *noInicial) {
    Node *aux;
    int cont;

    if(*noInicial == NULL) return 0;

    for (cont = 0, aux = *noInicial; aux != NULL ; aux = aux->prox, ++cont);
    return cont;
}