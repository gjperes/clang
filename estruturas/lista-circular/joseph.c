#include "joseph.h"

struct Soldado {
    char dado[50];
    struct Soldado *prox;
};

// Cria um nó e retorna ele na função
Node* criarSoldado() {
    Node *novoSoldado;
    novoSoldado = (Node *) malloc(sizeof(Node));

    if(!novoSoldado) {
        printf("Problema de alocação\n");
        exit(0);
    }

    return novoSoldado;
}

// Gera a lista de soldados a partir de uma string
void criarListaSoldados(char *nomes, Node **soldados) {
    for(int i = 0; i < nomes[i + 1] != '\0'; i++) {
        Node *novoSoldado;

        novoSoldado = criarSoldado();
        novoSoldado->dado = nomes[i];

        // Se a lista de soldados estiver vazia, faça
        if(*soldados == NULL) {
            soldado->prox = soldado;
            *soldados = soldado; // Define o ponteiro que marca o início da lista para esse novo nó
        } else {
            Nodo *aux;

            aux = *soldados;
            // aux inicializado no primeiro nó da lista, percorre até o último nó
            while(aux->prox != *soldados) {
                aux = aux->prox;
            }
            // no último nó, aponta para o novo nó criado, que por sua vez, aponta para o início (circular)
            aux->prox = soldado;
            soldado->prox = *soldados;
        }
    }
}

// TODO completar essa função
void definirSoldado(Node **soldados, char *nomeInicial, int contagem) {
    int contador = 0;
    Node *aux;

    aux = *soldados;

    while(aux->prox != *soldados) {
        aux = aux->prox;
        contador++;
    }

    while(contador > 1) {
        aux = *soldados;

        // Cara pode digitar um nome que não existe
        while(aux->dado != nomeInicial) {
            aux = aux->prox;
        }

        for(int x = 0; x < contagem - 1; x++)
        {
            aux = aux->prox;
        }

        nomeInicial = (aux->prox)->dado;
        printf("%c\n", removerSoldado(aux, aux->prox));

        aux-1 aux  aux+1//Remover

    }
}

// TODO, refazer isso aqui:
char[] removerSoldado(Node **soldadoAnterior, Node **soldado) {
    Node *aux;

    char[] nomeRemovido = (*soldado)->dado;
    *dado = aux->dado;

    if(*C == p) //Lista com apenas um nodo
        *C = NULL;
    else
        (*C)->prox = p->prox;

    free(soldado);
    return nomeRemovido;
}
