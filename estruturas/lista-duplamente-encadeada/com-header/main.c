#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamente.h"

void imprimir_menu() {
    printf("\n1. Insere no início da Lista\n");
    printf("2. Remove do início da Lista\n");
    printf("3. Insere no fim da Lista\n");
    printf("4. Exclui do fim da Lista\n");
    printf("5. Imprime Lista\n");
    printf("6. Verifica o tamanho da Lista\n");
    printf("0. Sair\n");
}

int main(int argc, char *argv[]) {
    Header *MyList;
    int menu, valor;

    iniciar_header(MyList);

    do {
        imprimir_menu();
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("Informe o valor a ser inserido no início da lista: ");
                scanf("%d", &valor);
                inserir_inicio_lista(MyList, valor);
                break;
            case 2:
                if(remover_inicio_lista(MyList))
                    printf("Exclusão feita com sucesso\n");
                else
                    printf("Não foi possível excluir\n");
                break;
            case 3:
                printf("Informe o valor a ser inserido no final da lista: ");
                scanf("%d", &valor);
                inserir_final_lista(MyList, valor);
                break;
            case 4:
                if(remover_final_lista(MyList))
                    printf("Exclusão feita com sucesso\n");
                else
                    printf("Não foi possível excluir\n");
                break;
            case 5:
                imprimir_lista(MyList);
                break;
            case 6:
                printf("A lista possui %d elementos\n", MyList->tamanhoLista);
                break;
            case 0:
                printf("\nSaindo do programa!\n");
                break;
            default:
                printf("Opção Inválida!\n");
        }
    } while(menu != 0);

    liberar_lista(MyList);

    return 0;
}