#include <stdio.h>
#include <stdlib.h>
#include "listaDinEncadeada.h"

void imprimirMenu() {
    printf("\n1. Insere no fim da Lista\n");
    printf("2. Remove do fim da Lista\n");
    printf("3. Insere no inicio da Lista\n");
    printf("4. Exclui do inicio da Lista\n");
    printf("5. Imprime Lista\n");
    printf("6. Verifica o tamanho da Lista\n");
    printf("7. Verifica se a Lista está vazia\n");
    printf("8. Consultar uma posição na Lista\n");
    printf("9. Consultar um valor na Lista\n");
    printf("0. Sair\n");
}

int main(int argc, char *argv[]) {
    Node *MyList;
    int menu, valor;

    iniciarLista(&MyList);

    do {
        imprimirMenu();
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("Informe o valor a ser inserido no final da lista: ");
                scanf("%d", &valor);
                inserirFinalLista(&MyList, valor);
                break;
            case 2:
                if(removerFinalLista(&MyList, &valor) == 0)
                    printf("A lista está vazia!\n");
                else
                    printf("O valor excluído do final da lista foi: %d\n", valor);
                break;
            case 3:
                printf("Informe o valor a ser inserido no inicio da lista: ");
                scanf("%d", &valor);
                inserirInicioLista(&MyList, valor);
                break;
            case 4:
                if(removerInicioLista(&MyList, &valor) == 0)
                    printf("A lista está vazia!\n");
                else
                    printf("O valor excluído do inicio da lista foi: %d\n", valor);
                break;
            case 5:
                printf("\nImprimindo lista:\n");
                imprimirLista(MyList);
                printf("Fim\n");
                break;
            case 6:
                printf("A lista possui %d elementos\n", verificarTamanhoLista(MyList));
                break;
            case 7:
                if(verificarListaVazia(MyList) != 0) {
                    printf("A lista está vazia\n");
                } else {
                    printf("A lista possui elementos\n");
                }
                break;
            case 8:
                printf("Informe a posição a ser consultada na lista: ");
                scanf("%d", &valor);
                if(consultarPosicaoLista(MyList, valor, &valor) != 0) {
                    printf("A posição existe, e nela possui o dado: %d\n", valor);
                } else {
                    printf("A posição informada não existe\n");
                }
                break;
            case 9:
                printf("Informe o elemento a ser consultado na lista: ");
                scanf("%d", &valor);

                int resultado = consultarElementoLista(MyList, valor);

                if(resultado != -1) {
                    printf("Elemento encontrado na posição: %d\n", resultado);
                } else {
                    printf("Não foi possível localizar o elemento na lista\n");
                }
                break;
            case 0:
                printf("\nSaindo do programa!\n");
                break;
            default:
                printf("Opção Inválida!\n");
        }
    } while(menu != 0);

    liberarLista(&MyList);

    return 0;
}