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



// // Gera a lista de soldados a partir de uma string - ANTIGO REVER
// void criarListaSoldados(char *nomes, Node **soldados) {
//     for(int i = 0; i < nomes[i + 1] != '\0'; i++) {
//         Node *novoSoldado;

//         novoSoldado = criarSoldado();
//         novoSoldado->dado = nomes[i];

//         // Se a lista de soldados estiver vazia, faça
//         if(*soldados == NULL) {
//             soldado->prox = soldado;
//             *soldados = soldado; // Define o ponteiro que marca o início da lista para esse novo nó
//         } else {
//             Nodo *aux;

//             aux = *soldados;
//             // aux inicializado no primeiro nó da lista, percorre até o último nó
//             while(aux->prox != *soldados) {
//                 aux = aux->prox;
//             }
//             // no último nó, aponta para o novo nó criado, que por sua vez, aponta para o início (circular)
//             aux->prox = soldado;
//             soldado->prox = *soldados;
//         }
//     }
// }

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
