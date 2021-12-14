// Faça um programa que apresente os números de 1 a 15 na forma de um triangulo, usando só 1 laço loop
// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10 
// 11 12 13 14 15

#include <stdio.h>

int counter;

int main(void){
    for (counter=1; counter<16; counter++){
        if (counter==2 || counter==4 || counter==7 || counter==11){
            printf("\n");
        }
        printf("%d ", counter);
    }
    printf("\n");
    return 0;
}