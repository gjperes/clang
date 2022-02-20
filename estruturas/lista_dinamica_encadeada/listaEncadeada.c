#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

Lista *criaLista()
{
  Lista *novaLista = (Lista *)malloc(sizeof(Lista));

  if (novaLista != NULL)
  {
    novaLista = NULL;
  }

  return novaLista;
}

void liberaLista(Lista *li)
{
  if (li != NULL)
  {
    Lista *node;
    while ((*li) != NULL)
    {
      node = *li;
      *li = (*li)->prox;
      free(node);
    }
    free(li);
  }
}

int verificaListaVazia(Lista *li)
{
  if (li == NULL)
    return 1;
  if (*li == NULL)
    return 1;
  return 0;
}

int verificaTamanhoLista(Lista *li)
{
  if (li == NULL)
    return 0;

  int contador = 0;
  Lista *node = *li;

  while (node != NULL)
  {
    contador++;
    node = (*node)->prox;
  }

  return contador;
}
