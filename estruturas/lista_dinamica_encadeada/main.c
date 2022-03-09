#include <stdio.h>
#include <stdlib.h>
#include "listaDinEncadeada.h"

void imprimirMenu() {
    printf("\n1. Insere no fim da Lista\n");
    printf("2. Insere no inicio da Lista\n");
    printf("3. Exclui do inicio da Lista\n");
    printf("4. Imprime Lista\n");
    printf("5. Sair\n");
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
                printf("Informe o valor a ser inserido no inicio da lista: ");
                scanf("%d", &valor);
                inserirInicioLista(&MyList, valor);
                break;
            case 3:
                if(removerInicioLista(&MyList, &valor) == 0)
                    printf("A lista está vazia!!\n");
                else
                    printf("O valor excluído do inicio da lista foi: %d\n", valor);
                break;
            case 4:
                imprimirLista(MyList);
                break;
            case 5:
                printf("\nSaindo do programa!\n");
                break;
            case 6:
                liberarLista(&MyList);
                imprimirLista(MyList);
                break;
            default:
                printf("Opção Inválida!\n");
        }
    } while(menu != 5);

    return 0;
}