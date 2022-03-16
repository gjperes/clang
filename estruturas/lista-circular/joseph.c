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
        primeiroNode = proxAux->prox;

    free(proxAux);

    Lista->tamanhoLista--;
}

// // TODO ANTIGO - REVER
// void definirSoldado(Node **soldados, char *nomeInicial, int contagem) {
//     int contador = 0;
//     Node *aux;

//     aux = *soldados;

//     while(aux->prox != *soldados) {
//         aux = aux->prox;
//         contador++;
//     }

//     while(contador > 1) {
//         aux = *soldados;

//         // Cara pode digitar um nome que não existe
//         while(aux->dado != nomeInicial) {
//             aux = aux->prox;
//         }

//         for(int x = 0; x < contagem - 1; x++)
//         {
//             aux = aux->prox;
//         }

//         nomeInicial = (aux->prox)->dado;
//         printf("%c\n", removerSoldado(aux, aux->prox));

//         aux-1 aux  aux+1//Remover

//     }
// }
