#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main() {
  Arvore * a;
  srand(time(NULL));

  for(int i=0;i<100000;i++) {
    int r = rand() % 100000;
    a = inserir(a, r);
  }

  printf("\n");
  // pre_order(a);
  printf("Máx=%d", max(*a));
  printf(" Mín=%d", min(*a));
  // if (buscar(a, 100000))
  //   printf("Achou");
  // else
  //   printf("Não achou");
  printf("\n");
}
