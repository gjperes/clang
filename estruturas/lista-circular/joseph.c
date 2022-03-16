#include <stdio.h>
#include <stdlib.h>
#include "joseph.h"

void inicializaLista(Header *Lista) {
    Lista->primeiroNode = NULL;
}

// Cria um nó e retorna ele na função [OK]
NodeSoldado* criarNode() {
    NodeSoldado *novoNode;
    novoNode = (NodeSoldado *)malloc(sizeof(NodeSoldado));

    if(!novoNode) {
        printf("Problema de alocação\n");
        exit(0);
    }

    return novoNode;
}

// Insere o nó Soldado na lista [OK]
void inserirSoldado(Header *Lista, char nomeSoldado[TAM_NOME]) {
    NodeSoldado *novoSoldado = criarNode();

    novoSoldado->dado[0] = nomeSoldado[0];

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

// Remove o nó de um Soldado da lista, retorna Bool informando sucesso ou não na remoção [OK]
int removerSoldado(Header *Lista, char nomeSoldado[TAM_NOME]) {
    if(Lista->primeiroNode == NULL) return 0;
    if(Lista->tamanhoLista == 1) {
        printf("Exception: A lista contém apenas o último soldado, "
               "que deve ser removido manualmente pelo programa!\n");
        return 0;
    }

    NodeSoldado *aux, *proxAux;

    aux = Lista->primeiroNode;
    while((aux->prox)->dado != nomeSoldado) {
        aux = aux->prox;
    }
    proxAux = aux->prox; // posição em memória do nó que será removido
    aux->prox = proxAux->prox; // posição em memória anterior ao nó que será removido

    // Se o nó que será removido for o mesmo do início da lista,
    // pegamos o nó apontado de próx e definimos ele como começo da lista
    if(proxAux == Lista->primeiroNode) {
        Lista->primeiroNode = proxAux->prox;
    }

    free(proxAux);

    Lista->tamanhoLista--;
    return 1;
}
