#include <stdio.h>
#include <stdlib.h>
#include "joseph.h"

struct _NodeSoldado {
    char dado[50];
    struct _NodeSoldado *prox;
};

struct _Cabecalho {
    int tamanhoLista = 0;
    NodeSoldado *primeiroNode;
};

void inicializaLista(Cabecalho *Lista) {
    Lista->primeiroNode = NULL;
}

// Cria um nó e retorna ele na função OK
NodeSoldado* criarNode() {
    NodeSoldado *novoNode;
    novoNode = (Node *)malloc(sizeof(Node));

    if(!novoNode) {
        printf("Problema de alocação\n");
        exit(0);
    }

    return novoNode;
}

// ok
void inserirSoldado(Cabecalho *Lista, char nomeSoldado[TAM_NOME]) {
    NodeSoldado *novoSoldado = criarNode();

    novoSoldado->dado = nomeSoldado;

    if(Lista->primeiroNode == NULL) {
        Lista->primeiroNode = novoSoldado;
        novoSoldado->prox = Lista->primeiroNode;
    } else {
        NodeSoldado *aux;

        aux = Lista->primeiroNode;

        while(aux->prox != Lista->primeiroNode) {
            aux = aux->prox;
        }

        aux->prox = novoSoldado;
        novoSoldado->prox = Lista->primeiroNode;
    }
    
    Lista->tamanhoLista++;
}

// ok -> boa sorte pra entender ;)
int removerSoldado(Cabecalho *Lista, char nomeSoldado[TAM_NOME]) {
    if(Lista->primeiroNode == NULL) return 0;

    NodeSoldado *aux, *proxAux;

    aux = Lista->primeiroNode;
    while((aux->prox)->dado != nomeSoldado) {
        aux = aux->prox;
    }
    proxAux = aux->prox;
    aux->prox = proxAux->prox;

    if(proxAux == Lista->primeiroNode)
        Lista->primeiroNode = proxAux->prox;

    free(proxAux);

    Lista->tamanhoLista--;
    return 1;
}
