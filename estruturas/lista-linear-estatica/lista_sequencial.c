#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

struct Vetor {
  int dados[MAX_VETOR];
  int inicio, fim;
};

Tipo_Lista* criarLista() {
  Tipo_Lista *novaLista;

  novaLista = (Tipo_Lista *)malloc(sizeof(Tipo_Lista));

  if(novaLista != NULL)
    novaLista->fim = 0;

  return novaLista;
}