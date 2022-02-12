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

int inserirOrdenadoLista(Tipo_Lista *lista, int valor) {
  
  if(lista == NULL) return 0;
  if(verificarListaCheia(lista)) return 0;

  int i = 0;

  // Percorre a lista comparando os valores com o novo dado a ser inserido, 
  // Assim que o novo dado for maior que o número comparado, interrompe.
  while(i < lista->fim && valor > lista->dados[i])
    i++;
  
  // "Joga" pro lado os valores, pra inserir o novo dado no meio da lista
  for(int j = (lista->fim - 1); j >= i; j--) {
    lista->dados[j + 1] = lista->dados[j];
  }

  lista->dados[i] = valor;
  lista->fim++;

  return 1;
}

int removerInicioLista(Tipo_Lista *lista) {
  if(lista == NULL) return 0;
  if(verificarListaVazia) return 0;

  for(int i = 0; i < (lista->fim - 1); i++) {
    lista->dados[i] = lista->dados[i + 1];
  }

  lista->fim--;

  return 1;
}

int removerFinalLista(Tipo_Lista *lista) {
  if(lista == NULL) return 0;
  if(verificarListaVazia) return 0;

  lista->dados[lista->fim] = 0;
  lista->fim--;

  return 1;
}

int removerMeioLista(Tipo_Lista *lista, int valor) {
  if(lista == NULL) return 0;
  if(verificarListaVazia) return 0;

  int i = 0;

  // Percorre a lista procurando o valor informado
  while(i < lista->fim && valor != lista->dados[i])
    i++;
  
  // Se percorreu a lista completamente e não encontrou o valor, não teve sucesso
  if(i == lista->fim) return 0;

  for(int k = i; k < (lista->fim - 1); k++) {
    lista->dados[k] = lista->dados[k + 1];
  }

  lista->fim--;

  return 1;
}

int consultarConteudoLista(Tipo_Lista *lista, int valor) {
  if (lista == NULL || verificarListaVazia(lista)) 
    return 0;

  for(int i = 0; i <= lista->fim; i++) {
    if(lista->dados[i] == valor)
      return 1;
  }

  return 0;
}

int consultarPosicaoLista(Tipo_Lista *lista, int posicao) {
  if (lista == NULL || verificarListaVazia(lista)) 
    return 0;
  
  if(lista->fim < posicao || posicao < 0)
    return 0;

  return 1;
}

int imprimirLista(Tipo_Lista *lista) {
  if(lista == NULL) {
    printf("Lista não criada.\n");
    return 0;
  }

  if(verificarListaVazia(lista)) {
    printf("É uma lista vazia.\n");
    return 0;
  }

  printf("Imprimindo lista...\n");
  for(int i = 0; i <= lista->fim; i++) {
    printf("%d\n", lista->dados[i]);
  }

  return 1;
}