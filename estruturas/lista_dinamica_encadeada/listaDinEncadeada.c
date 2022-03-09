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
    if (*noInicial == NULL) return 0;

    Node *aux;

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

    if (*noInicial == NULL) return 0;

    for (cont = 0, aux = *noInicial; aux != NULL; aux = aux->prox, ++cont);
    return cont;
}

int verificarListaVazia(Node *noInicial) {
    if (noInicial == NULL) return 1;
    return 0;
}

int removerFinalLista(Node **noInicial, int *retorno) {
    if (*noInicial == NULL) return 0;
    if ((*noInicial)->prox == NULL) {
        free(*noInicial);
        return 1;
    }

    Node *aux, *auxRemover;
    aux = *noInicial;

    // Coloca o *aux no penúltimo elemento da lista
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    // auxRemover passa a apontar pro último elemento
    auxRemover = aux->prox;
    // Libera o último
    free(auxRemover);
    // O penúltimo passa a apontar pra NULL
    aux->prox = NULL;

    return 1;
}

int consultarPosicaoLista(Node *noInicial, int posicao, int *retorno) {
    Node *aux;
    int cont = 0;

    aux = noInicial;
    while ((aux != NULL) && (cont < posicao)) {
        aux = aux->prox;
        cont++;
    }
    if (aux == NULL) {
        return 0;
    }
    *retorno = aux->dado;
    return 1;
}