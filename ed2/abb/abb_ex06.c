#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
  int info;
  struct arvore *esq;
  struct arvore *dir;
} Arvore;

int buscar (Arvore *a, int v) {
  if (a == NULL) { return 0; } /*Nao achou*/
  else if (v < a->info) {
    return buscar (a->esq, v);
  }
  else if (v > a->info) {
    return buscar (a->dir, v);
  }
  else { return 1; } /*Achou*/
}

Arvore* inserir (Arvore *a, int v) {
  if (a == NULL) {
    a = (Arvore*)malloc(sizeof(Arvore));
    a->info = v;
    a->esq = a->dir = NULL;
  }
  else if (v < a->info) {
    a->esq = inserir (a->esq, v);
  }
  else { a->dir = inserir (a->dir, v); }
  return a;
}

void in_order(Arvore *a){
  if(!a)
    return;
  in_order(a->esq);
  printf("%d ",a->info);
  in_order(a->dir);
}

void pre_order(Arvore *a){
  printf("< %d ", a->info);
  if (a->esq != NULL) pre_order(a->esq);
  else printf("< > ");
  if (a->dir != NULL) pre_order(a->dir);
  else printf("< > ");
  printf("> ");
}

void print(Arvore * a,int spaces){
  int i;
  for(i=0;i<spaces;i++) printf(" ");
  if(!a){
    printf("\n");
    return;
  }

  printf("%d\n", a->info);
  print(a->esq,spaces+2);
  print(a->dir,spaces+2);
}

int max(Arvore a) {
  if (a.dir == NULL) return a.info;
  return max(*(a.dir));
}

int min(Arvore a) {
  if (a.esq == NULL) return a.info;
  return min(*(a.esq));
}

Arvore* remover(Arvore *a, int rem) {
  Arvore *aux;
  // passo 1 ok
  if (a == NULL) return NULL;

  // comparar o valor com o nó raiz
  if (rem < a->info) a->esq = remover(a->esq, rem);
  if (rem > a->info) a->dir = remover(a->dir, rem);
  
  // não, já estou no nó a ser removido
  // CASO 1 - nó folha
  if (a->esq == NULL && a->dir == NULL) {
    free(a);
    return NULL;
  // CASO 2 - Só uma subárvore
  } else if (a->esq == NULL && a->dir != NULL) {
    // uso um auxiliar para "subir" o nó "órfão"
    aux = a->dir;
    // removo o nó atual
    free(a);
    return aux;
  } else if (a->dir == NULL && a->esq != NULL) {
    // uso um auxiliar para "subir" o nó "órfão"
    aux = a->esq;
    // removo o nó atuals
    free(a);
    return aux;
  } else {
    // CASO 3 - Duas subárvores
    aux = a->esq;
    while(aux->dir != NULL) {
      aux = aux->dir;
    }
    // aux é o endereço do nó imediatamente menor
    int temp = aux->info;
    // "inverto" os nós
    aux->info = a->info;
    a->info = temp;
    remover(aux, temp);
    return a;
  }

  return a;
}

int main() {
  Arvore * a;

  a = inserir(NULL,50);
  a = inserir(a,30);
  a = inserir(a,90);
  a = inserir(a,20);
  a = inserir(a,40);
  a = inserir(a,95);
  a = inserir(a,10);
  a = inserir(a,35);
  a = inserir(a,45);
  a = inserir(a,37);

  printf("\n");
  printf("\n");
}
