#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct arvore {
  int info;
  struct arvore *esq;
  struct arvore *dir;
} Arvore;


Arvore*  cria_arv_vazia (void);
Arvore*  arv_constroi (int n, Arvore* e, Arvore* d);
int      verifica_arv_vazia (Arvore* a);
Arvore*  arv_libera (Arvore* a);
int      arv_pertence (Arvore* a, int n);
void     arv_imprime (Arvore* a);
int      conta_nos(Arvore a);
int      max_arvore(Arvore a);
int      altura_arvore(Arvore *a);
int      nos_folha_arvore(Arvore *a);


Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* arv_constroi (int n, Arvore* e, Arvore* d) {
  Arvore* a = (Arvore*)malloc(sizeof(Arvore));
  a->info = n;
  a->esq = e;
  a->dir = d;
  return a;
}

int verifica_arv_vazia (Arvore* a) {
  return (a == NULL);
}

Arvore* arv_libera (Arvore* a) {
  if (!verifica_arv_vazia(a)) {
    arv_libera (a->esq);
    arv_libera (a->dir);
    free(a);
  }
  return NULL;
}

void arv_imprime (Arvore* a) {
  if (!verifica_arv_vazia(a->esq)) arv_imprime(a->esq);
  if (!verifica_arv_vazia(a->dir)) arv_imprime(a->dir);
  printf("%d ", a->info);
}

int arv_pertence (Arvore* a, int n) {
  if (verifica_arv_vazia(a)) return 0;
  if (arv_pertence(a->esq, n)) return 1;
  if (arv_pertence(a->dir, n)) return 1;

  if (a->info == n) return 1;
  return 0;
}

int conta_nos(Arvore a) {
  int sum = 0;

  if (!verifica_arv_vazia(a.esq))
    sum += conta_nos(*(a.esq));
  if (!verifica_arv_vazia(a.dir))
    sum += conta_nos(*(a.dir));
  return sum += 1;
}

int max_arvore(Arvore a) {
  int max = a.info;
  if (!verifica_arv_vazia(a.esq)) {
    int esq = max_arvore(*(a.esq));
    if (esq > max) max = esq;
  }
  if (!verifica_arv_vazia(a.esq)) {
    int dir = max_arvore(*(a.dir));
    if (dir > max) max = dir;
  }
  return max;
}

int altura_arvore(Arvore *a) {
  int qtd_nos = conta_nos(*a);
  return ceil(log2(qtd_nos));
}

int nos_folha_arvore(Arvore *a) {
  int sum = 0;

  if (!verifica_arv_vazia(a->esq)) sum += nos_folha_arvore(a->esq);
  if (!verifica_arv_vazia(a->dir)) sum += nos_folha_arvore(a->dir);
  if (verifica_arv_vazia(a->esq) && verifica_arv_vazia(a->dir))
    return sum += 1;

  return sum;
}

int main (int argc, char *argv[]) {
  Arvore *a, *a1, *a2, *a3, *a4, *a5;
  a1 = arv_constroi(4,cria_arv_vazia(),cria_arv_vazia());
  a2 = arv_constroi(2,cria_arv_vazia(),a1);
  a3 = arv_constroi(5,cria_arv_vazia(),cria_arv_vazia());
  a4 = arv_constroi(6,cria_arv_vazia(),cria_arv_vazia());
  a5 = arv_constroi(3,a3,a4);
  a  = arv_constroi(1,a2,a5);
  arv_imprime(a);

  printf("\nnúmero máx na ávore: %d, altura da árvore: %d\n", max_arvore(*a), altura_arvore(a));
  printf("qtd nós: %d\nnós folha: %d\n", conta_nos(*a), nos_folha_arvore(a));
  // char ch; 
  // scanf("\n%c", &ch);
  // // if (arv_pertence(a, ch)) printf("%c -> Pertence\n",ch);
  // // else printf("%c -> Não pertence\n",ch);
  return 0;
}
