#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct arvore {
  char info;
  struct arvore *esq;
  struct arvore *dir;
} Arvore;

Arvore*  cria_arv_vazia (void);
Arvore*  arv_constroi (char c, Arvore* e, Arvore* d);
int      verifica_arv_vazia (Arvore* a);
Arvore*  arv_libera (Arvore* a);
char     arv_pertence (Arvore* a, char c);
void     arv_imprime (Arvore* a);
int      conta_nos(Arvore a);
int      max_arvore(Arvore a);
int      altura_arvore(Arvore *a);
int      nos_folha_arvore(Arvore *a);
int      eh_espelho(Arvore * arv_a, Arvore * arv_b);
Arvore*  cria_espelho(Arvore * arv_a);

Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* arv_constroi (char c, Arvore* e, Arvore* d) {
  Arvore* a = (Arvore*)malloc(sizeof(Arvore));
  a->info = c;
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

// pré-ordem
void arv_imprime (Arvore* a) {
  printf("< %c ", a->info);
  if (!verifica_arv_vazia(a->esq)) arv_imprime(a->esq);
  else printf("< > ");
  if (!verifica_arv_vazia(a->dir)) arv_imprime(a->dir);
  else printf("< > ");
  printf("> ");
}

char arv_pertence (Arvore* a, char c) {
  if (verifica_arv_vazia(a)) return 0;
  if (arv_pertence(a->esq, c)) return 1;
  if (arv_pertence(a->dir, c)) return 1;

  if (a->info == c) return 1;
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

// Retorna 1 se são espelhos, 0 se não
int eh_espelho(Arvore * arv_a, Arvore * arv_b) {
  // Primeiro, valida nulo, pra não tomar Seg fault na boca
  if (verifica_arv_vazia(arv_a) || verifica_arv_vazia(arv_b)) {
    if (verifica_arv_vazia(arv_a) == verifica_arv_vazia(arv_b)) 
    // se ambos espelhos são nulos == verdadeiro, retorna 1
      return 1;
    // se só 1 for null, não é espelho, e retorna 0
    return 0;
  }

  // se os valores não forem espelhados, retorna 0
  if (arv_a->info != arv_b->info) return 0;

  // verifica se todos os nós "filhos" são espelhos
  int esq = eh_espelho(arv_a->esq, arv_b->dir);
  int dir = eh_espelho(arv_a->dir, arv_b->esq);

  // se for o caso, retorna verdadeiro, 1
  if (esq == 1 && dir == 1) return 1;
  // se não, retorna 0
  return 0;
}

int main (int argc, char *argv[]) {
  Arvore *a, *a1, *a2, *a3, *a4, *a5;
  a1 = arv_constroi('d',cria_arv_vazia(),cria_arv_vazia());
  a2 = arv_constroi('b',cria_arv_vazia(),a1);
  a3 = arv_constroi('e',cria_arv_vazia(),cria_arv_vazia());
  a4 = arv_constroi('f',cria_arv_vazia(),cria_arv_vazia());
  a5 = arv_constroi('c',a3,a4);
  a  = arv_constroi('a',a2,a5);
  arv_imprime(a);
  printf("\n");

  // printf("número máx na ávore: %d", max_arvore(*a));
  printf("altura da árvore: %d\n", altura_arvore(a));
  printf("qtd nós: %d\nnós folha: %d\n", conta_nos(*a), nos_folha_arvore(a));

  Arvore *b, *b1, *b2, *b3, *b4, *b5;
  b1 = arv_constroi('d',cria_arv_vazia(),cria_arv_vazia());
  b2 = arv_constroi('b',b1,cria_arv_vazia());
  b3 = arv_constroi('e',cria_arv_vazia(),cria_arv_vazia());
  b4 = arv_constroi('f',cria_arv_vazia(),cria_arv_vazia());
  b5 = arv_constroi('c',b4,b3);
  b  = arv_constroi('a',b5,b2);
  arv_imprime(b);
  printf("\n");

  if (eh_espelho(a, b)) 
    printf("é espelho\n");
  else
    printf("não é espelho\n");

  // char ch; 
  // scanf("\n%c", &ch);
  // // if (arv_pertence(a, ch)) printf("%c -> Pertence\n",ch);
  // // else printf("%c -> Não pertence\n",ch);
  return 0;
}
