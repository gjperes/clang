#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

// Imprime o menu e recebe do usuário a seleção desejada, que é um valor inteiro retornado pela função
int imprimirMenu()
{
  int selecaoMenu;

  printf("MENU PRINCIPAL - Selecione a operação desejada:\n");
  printf(" 1 - Criar a lista estática\n");
  printf(" 2 - Liberar  lista estática\n");
  printf(" 3 - Inserir no início\n");
  printf(" 4 - Inserir no fim\n");
  printf(" 5 - Inserir no meio (ordenado)\n");
  printf(" 6 - Remover do início\n");
  printf(" 7 - Remover do fim\n");
  printf(" 8 - Remover do meio\n");
  printf(" 9 - Consultar pelo conteúdo\n");
  printf("10 - Consultar pela posição\n");
  printf("11 - Imprimir Lista Estática\n");
  printf("12 - Sair\n");
  printf("\n");
  scanf("%d", &selecaoMenu);

  return selecaoMenu;
}

int main(int argc, char **argv)
{
  Tipo_Lista *li = NULL;
  int operacaoMenu;
  int inputUser;

  do
  {
    operacaoMenu = imprimirMenu();
    if (operacaoMenu == 12)
      break;

    switch (operacaoMenu)
    {
    case 1:
      if (li != NULL)
        liberarLista(li);

      li = criarLista();
      break;

    case 2:
      liberarLista(li);
      break;

    case 3:
      printf("Dado a ser inserido no início: ");
      scanf("%d", &inputUser);

      if (!(inserirInicioLista(li, inputUser)))
        printf("ERRO: Erro ao inserir\n");
      break;

    case 4:
      printf("Dado a ser inserido no final: ");
      scanf("%d", &inputUser);

      if (!(inserirFinalLista(li, inputUser)))
        printf("ERRO: Erro ao inserir\n");
      break;

    case 5:
      printf("Dado a ser inserido no final: ");
      scanf("%d", &inputUser);

      if (!(inserirOrdenadoLista(li, inputUser)))
        printf("ERRO: Erro ao inserir\n");
      break;

    case 6:
      if (!(removerInicioLista(li)))
        printf("ERRO: Erro ao remover\n");
      break;

    case 7:
      if (!(removerFinalLista(li)))
        printf("ERRO: Erro ao remover\n");
      break;

    case 8:
      printf("Dado a ser removido: ");
      scanf("%d", &inputUser);

      if (!(removerMeioLista(li, inputUser)))
        printf("ERRO: Erro ao remover\n");
      break;

    case 9:
      printf("Dado a ser localizado na lista: ");
      scanf("%d", &inputUser);

      if (consultarConteudoLista(li, inputUser))
      {
        printf("O dado existe na lista\n");
      }
      else
      {
        printf("O dado NÃO existe na lista\n");
      }
      break;

    case 10:
      printf("Posição a ser localizada na lista: ");
      scanf("%d", &inputUser);

      if (consultarPosicaoLista(li, inputUser))
      {
        printf("A posição existe na lista\n");
      }
      else
      {
        printf("A posição NÃO existe na lista\n");
      }
      break;

    case 11:
      if (!(imprimirLista(li)))
        printf("ERRO: Erro ao imprimir a lista!\n");
      break;

    default:
      printf("ERRO: Seleção inválida\n");
    }

    printf("==========================================\n");
  } while (operacaoMenu != 12);

  printf("Fim da execução.");
  return 0;
}