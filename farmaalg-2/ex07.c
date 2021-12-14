// E07) Faça um programa que faça a operação de swap entre as variáveis x e y, sem o uso de uma terceira variável, utilizando apenas operadores binários.

// Complemente o código abaixo ( o código abaixo deve ser informado para o farmalg):

// int main( void ) {
// int x=5, y=-10;
// printf("x=%d y=%d\n",x,y);
// /* complemente este código */
// printf("x=%d y=%d\n",x,y);
// }

#include <stdio.h>

int main( void ) {

    int x=5, y=-10;

    printf("x=%d y=%d\n",x,y);
    
    while(x != -10) {
        x--;
    }

    while(y != 5){
        y++;
    }

    printf("x=%d y=%d\n",x,y);

    return 0;
}