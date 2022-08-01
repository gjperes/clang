#include <stdio.h>
#include <stdlib.h>

typedef struct {
  // array para armazenar as compoentes de cada elemento;
  int * id;
  // número de elementos
  int n;
  // contagem de componentes atual;
  int count;
} UF;

// inicializa N itens com nomes de inteiros (0 até N-1)
UF * init_UF(int n);
// retorna o número de componentes
int count_UF(UF * uf);
// retorna true se p e q estão na mesma componente
int connected_UF(UF * uf, int p, int q);
// identifica a componente de p (0 até N-1)
int find_UF(UF * uf, int p);
// adiciona conexão entre p e q
void union_UF(UF * uf, int p, int q);

UF * init_UF(int n) {
  int i;
  UF * uf;

  uf = malloc(sizeof(UF));

  uf->id = malloc(sizeof(int) * n);
  uf->n = n;
  uf->count = n;
  for (i = 0; i < uf->count; ++i) {
    uf->id[i] = i;
  }

  return(uf);
}

int count_UF(UF * uf) {
  return(uf->count);
}

int connected_UF(UF * uf, int p, int q) {
  return(find_UF(uf, p) == find_UF(uf, q));
}

int find_UF(UF * uf, int p) {
  // se é o nó pai, retorna a posição dele
  if (uf->id[p] == p) return p;

  // se não for o nó pai, acessa recursivamente a posição apontada, 
  // até encontrar o nó pai
  find_UF(uf, uf->id[p]);
}

void union_UF(UF * uf, int p, int q) {

  if (uf->id[p] != p)
  // se P está ligado a outro nó, conecta Q em P
    uf->id[q] = p;
  else 
    uf->id[p] = q;

  uf->n--;
  
  return;
}

int main() {
  int n, p, q;
  UF * uf;

  scanf("%d", &n);
  
  uf = init_UF(n);

  scanf("%d %d", &p, &q);
  while(p > -1 && q > -1) {

    if(!connected_UF(uf, p, q)) {
      printf("%d %d\n", p, q);
      union_UF(uf, p, q);
    }

    scanf("%d %d", &p, &q);
  }
}
