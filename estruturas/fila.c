// 3 funções necessárias:
// enqueue
// dequeue
// clear
// Estruturas: tail e head

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void exibe(int *fila){
    int *p = fila;

    while(*p){
        printf("%d ", *p);
        p++;
    }
    printf("\n");
}

void enqueue(int *fila, int tail, int valor) {
    fila += tail; // fila na posição atual do tail
    *fila = valor; // ** recebe o valor
}

void dequeue(int *fila, int head, int tail){
    int *p = fila;
    p += head;
    *p = 0;
}

void clear(int *fila){
    while(*fila){
        *fila = 0;
        fila++;
    }
}

int main(){
    int fila[TAM], tail=0, head=0, selec;
    int num;

    do{ 
        exibe(fila);

        printf("\n1 - Enqueue / 2 - Dequeue / 3 - Clear / 0 - Sair\n");
        scanf("%d", &selec);

        switch(selec){
            case 1:
                scanf("%d", &num);
                if(tail < TAM){
                    enqueue(fila, tail, num);
                    tail++;
                }
                break;
            case 2:
                if(head < tail) {
                    dequeue(fila, head, tail);
                    head++;
                }
                break;
            case 3:
                clear(fila);
                break;
            case 0:
                break;
            default:
                break;
        }

    } while(selec);

    return 0;
}