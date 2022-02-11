#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

struct Vetor {
  int dados[MAX_VETOR];
  int fim;
};

Tipo_Lista* criarLista() {
  Tipo_Lista *novaLista;

  novaLista = (Tipo_Lista *)malloc(sizeof(Tipo_Lista));

  if(novaLista != NULL)
    novaLista->fim = 0;

  return novaLista;
}

void liberarLista(Tipo_Lista *lista) {
  free(lista);
}

int verificarListaCheia(Tipo_Lista *lista) {
  if(lista == NULL) 
    return (-1);

  return (lista->fim == MAX_VETOR);
}

int verificarListaVazia(Tipo_Lista *lista) {
  if(lista == NULL)
    return (-1);

  return (lista->fim == 0);
}

int inserirInicioLista(Tipo_Lista *lista, int valor) {
  if(lista == NULL) return 0;
  if(verificarListaCheia(lista)) return 0;
  
  if(!verificarListaVazia(lista)) {
    for(int i = (lista->fim - 1); i >= 0; i--) {
      lista->dados[i + 1] = lista->dados[i];
    }
  }

  lista->dados[0] = valor;
  lista->fim++;

  return 1;
}

int inserirFinalLista(Tipo_Lista *lista, int valor) {
  if(lista == NULL) return 0;
  if(verificarListaCheia(lista)) return 0;
  
  lista->dados[lista->fim] = valor;
  lista->fim++;

  return 1;
}

// TODO: Implementar a inserção no meio (ordenado)

// TODO: Precisa ser concluído
int removerInicioLista(Tipo_Lista *lista) {
  if(lista == NULL) return 0;
  if(verificarListaVazia) return 0;

  lista->dados[0] = 0;

  return 1;
}