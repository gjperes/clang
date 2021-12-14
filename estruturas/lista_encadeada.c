#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
    int valor; // aqui valor é um int, mas poderia ser uma struct ou vários elementos, por exemplo
    struct _NODE *prox;
} NODE;

int main(int argc, char *argv[]) {
    NODE *primeiro=NULL, *aux, *novo;
    int input;
    
    do {
        printf("Digite um número ou 0 para encerrar: ");
        scanf("%d", &input);

        if (input) {
            novo = (NODE *)malloc(sizeof(NODE)); // reservamos a memória para o novo node
            novo->valor = input; // recebe os dados
            novo->prox = NULL; // o novo node sempre aponta para NULL

            if (primeiro == NULL) {
            // só vai executar a primeira vez, quando o primeiro node for vazio
                primeiro = novo; // define que o endereço do primeiro node é o endereço desse novo node
            }
            else {
                // coloca o ponteiro auxiliar no começo da lista
                aux = primeiro;
                while (aux->prox != NULL) {
                // enquanto o ponteiro da struct, que aponta para um próximo nó, apontar para um node, segue esse endereço
                    aux = aux->prox;
                }
                // chegando ao último elemento (que aponta para NULL), altera esse ponteiro, que deve apontar para o novo agora
                aux->prox = novo;
            }
        }

    } while(input);

    while(primeiro) {
    // enquanto o primeiro node tiver algum valor
        printf("%d\n", primeiro->valor);
        aux = primeiro; // o ponteiro auxiliar vai ser do mesmo endereço do primeiro node
        primeiro = primeiro->prox; // o primeiro node passa a assumir como endereço o endereço para qual ele apontava
        free(aux); // liberamos aux, que estava nessa posição antiga do primeiro node
    }

    return 0;
}