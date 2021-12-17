// Faça um programa que leia uma sequências de números terminadas por zero. 
// A cada número lido, o programa deverá alocar um NODE e inclui-lo em uma árvore binária, 
// de forma que os valores menores fiquem a esquerda e os maiores ou igual a direita. 
// No final o programa deverá apresentar os valores fazendo o percurso recursivo em ordem.

#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
   int num;
   struct _NODE *esquerda;
   struct _NODE *direita;
} NODE;

NODE *novoNode(int valor) {
   NODE *novo = NULL;

   novo = (NODE *)malloc(sizeof(NODE));
   if( novo != NULL ) {
       novo->num = valor;
       novo->esquerda = NULL;
       novo->direita = NULL;
   }

   return novo;
}

// recebe um nó e o novo nó criado
void insereNode(NODE *no, NODE *novo) {

    if(novo == NULL)
        return;

    if(no == NULL)
        return;

    if( no->num > novo->num ) {

        if( no->esquerda == NULL ) {
        // se a posição do nó à esquerda for livre, inserimos o novo nó nessa posição
            no->esquerda = novo;
        } else {
        // se não, fazemos uma recursão, buscando uma posição vazia na árvore
            insereNode(no->esquerda, novo); // passamos a posição do nó que fica à esquerda, e novamente esse novo nó
        }

    } else {
    // no caso do valor do novo nó ser maior que o nó comparado:
        if( no->direita == NULL ) {
            no->direita = novo;
        } else {
            insereNode(no->direita, novo); // mesma coisa que o à esquerda, acima
        }
    }
}

void exibeArvore(NODE *no) {

    if( no == NULL ) // só será verdade após percorrer toda a árvore
        return;

    if( no->esquerda != NULL )
        exibeArvore(no->esquerda);

    printf("%d\n", no->num);

    if( no->direita != NULL )
        exibeArvore(no->direita);
}

void liberaRamos(NODE *no) {

    if( no == NULL ) // só será verdade após percorrer toda a árvore
        return;

    if( no->esquerda != NULL ) {
        liberaRamos(no->esquerda);
        free(no->esquerda);
    }

    if( no->direita != NULL ) {
        liberaRamos(no->direita);
        free(no->direita);
    }
}

int main()
{
    NODE *raiz=NULL;
    int numero;

    scanf("%d", &numero);
    raiz = novoNode(numero);

    do {
        scanf("%d", &numero); // lemos o número
        if(numero)
            insereNode(raiz, novoNode(numero)); // criamos um novo nó com ele e inserimos na árvore
    } while(numero);
    
    exibeArvore(raiz); // passamos o endereço da árvore para exibição

    liberaRamos(raiz);
    free(raiz);

    return 0;
}