#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

struct Vetor {
  int dados[MAX_VETOR];
  int inicio, fim;
};

Tipo_Lista* criarLista(int *valores) {
  Tipo_Lista *novaLista;
  int i = 0;

  novaLista = (Tipo_Lista *)malloc(sizeof(Tipo_Lista));

  while(*valores) {
    novaLista->dados[i] = valores[i];
    
    i++;
    valores++;
  }

  return novaLista;
}