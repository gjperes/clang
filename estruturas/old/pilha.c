#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
    int linha;
    int coluna;
    struct _NODE *aponta;
} NODE;

typedef struct {
    NODE *topo;
} PILHA;

void criaPilha(PILHA *p, int linha, int coluna) {
    NODE *novo;
    
    novo = (NODE *)malloc(sizeof(NODE));

    // o novo nó recebe os dados
    novo->linha = linha;
    novo->coluna = coluna;

    // o novo nó aponta para o antigo topo da pilha
    novo->aponta = p->topo;

    // o topo da pilha passa a ser esse novo nó
    p->topo = novo;

    printf("Empilhando na pos: %d | %d\n", linha, coluna);
}

void removePilha(PILHA *p) {
    
    NODE *topo = p->topo; // inicia o topo da pilha como um nó auxiliar
    int linha, coluna;

    p->topo = topo->aponta; // o topo da pilha segue o endereço (o endereço do penúltimo elemento da pilha) apontado por esse nó
    
    // aqui serve apenas para apresentação visual
    linha = topo->linha;
    coluna = topo->coluna;
    printf("Removido pos: %d | %d\n", linha, coluna);
    // fim apresentação visual

    free(topo); // libera de memória o nó auxiliar
}

int main(){
    PILHA pilha;
    NODE *aux;
    int i;

    pilha.topo = NULL;

    for(i=0; i<10; i++)
        criaPilha(&pilha, i, i);
    
    printf("Esvaziando!\n");

    while(pilha.topo != NULL) {
        removePilha(&pilha);
    }

    return 0;
}