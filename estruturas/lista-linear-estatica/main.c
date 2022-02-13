#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

// Imprime o menu e recebe do usuário a seleção desejada, que é um valor inteiro retornado pela função
int imprimirMenu()
{
  int selecaoMenu;

  printf("MENU PRINCIPAL - Selecione a operação desejada:\n");
  printf(" 1 - Criar a lista estática\n");
  printf(" 2 - Liberar lista estática\n");
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
  printf("\nMENU PRINCIPAL - Seleção: ");
  scanf("%d", &selecaoMenu);

  return selecaoMenu;
}

/**
 * @brief A função recebe um boolean e 2 parâmetros string. Retorna o primeiro param. string se o bool for verdadeiro, do contrário, retorna o segundo param string.
 *
 * @param bool Boolean que valida qual string será retornada para a função
 * @param sucesso String a ser retornada caso o bool seja verdadeiro
 * @param falha String a ser retornada caso o bool seja falso
 * @return char*
 */
char *logFuncao(int bool, char *sucesso, char *falha)
{
  if (bool)
    return sucesso;
  return falha;
}

int main(int argc, char **argv)
{
  Tipo_Lista *li = NULL;
  int operacaoMenu;
  int inputUser;
  int observerFuncao;

  do
  {
    operacaoMenu = imprimirMenu();
    if (operacaoMenu == 12)
      break;

    switch (operacaoMenu)
    {
    case 1:
      li = criarLista();
      break;

    case 2:
      liberarLista(li);
      break;

    case 3:
      printf("Dado a ser inserido no início: ");
      scanf("%d", &inputUser);

      observerFuncao = inserirInicioLista(li, inputUser);
      printf("%s\n", logFuncao(observerFuncao, "Sucesso ao inserir", "Falha ao inserir"));
      break;

    case 4:
      printf("Dado a ser inserido no final: ");
      scanf("%d", &inputUser);

      observerFuncao = inserirFinalLista(li, inputUser);
      printf("%s\n", logFuncao(observerFuncao, "Sucesso ao inserir", "Falha ao inserir"));
      break;

    case 5:
      printf("Dado a ser inserido no final: ");
      scanf("%d", &inputUser);

      observerFuncao = inserirOrdenadoLista(li, inputUser);
      printf("%s\n", logFuncao(observerFuncao, "Sucesso ao inserir", "Falha ao inserir"));
      break;

    case 6:
      observerFuncao = removerInicioLista(li);
      printf("%s\n", logFuncao(observerFuncao, "Sucesso ao remover", "Falha ao remover"));
      break;

    case 7:
      observerFuncao = removerFinalLista(li);
      printf("%s\n", logFuncao(observerFuncao, "Sucesso ao remover", "Falha ao remover"));
      break;

    case 8:
      printf("Dado a ser removido: ");
      scanf("%d", &inputUser);

      observerFuncao = removerMeioLista(li, inputUser);
      printf("%s\n", logFuncao(observerFuncao, "Sucesso ao remover", "Falha ao remover"));
      break;

    case 9:
      printf("Dado a ser localizado na lista: ");
      scanf("%d", &inputUser);

      observerFuncao = consultarConteudoLista(li, inputUser);
      printf("%s\n", logFuncao(observerFuncao, "Valor localizado na lista", "Falha em localizar o valor"));

    case 10:
      printf("Posição a ser localizada na lista: ");
      scanf("%d", &inputUser);

      observerFuncao = consultarPosicaoLista(li, inputUser);
      printf("%s\n", logFuncao(observerFuncao, "Posição localizada na lista", "Falha em localizar a posição na lista"));

    case 11:
      imprimirLista(li);
      break;

    default:
      printf("ERRO MENU: Seleção inválida\n");
    }

    printf("==========================================\n");
  } while (operacaoMenu != 12);

  printf("Fim da execução\n");
  return 0;
}