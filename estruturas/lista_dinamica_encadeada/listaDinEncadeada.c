#include <stdio.h>

#include <stdlib.h>

#include "listaDinEncadeada.h"

struct _Lista {
    // Dados poderia ser uma struct
    int dados;
    struct _Lista *prox;
};

Lista *criaLista() {
    Lista *novaLista = (Lista *)malloc(sizeof(Lista));

    if (novaLista != NULL) {
        novaLista = NULL;
    }

    return novaLista;
}

void liberaLista(Lista **li) {
    if (*li != NULL) {
        Lista *aux;

        while ((*li) != NULL) {
            aux = *li;
            *li = (*li)->prox;
            free(aux);
        }

        free(li);
    }
}

int verificaListaVazia(Lista **li) {
    if (li == NULL)
        return 1;
    if (*li == NULL)
        return 1;
    return 0;
}

int verificaTamanhoLista(Lista **li) {
    if (li == NULL)
        return 0;

    int contador = 0;
    Lista *node = *li;

    while (node != NULL) {
        contador++;
        node = &(*node)->prox;
    }

    return contador;
}
