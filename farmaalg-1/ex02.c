// Faça um programa que apresente os números de 1 a 15 na forma de um triangulo

// num linha = num numeros exib. 
// saber num linha -> 

#include <stdio.h>

short int lineCount, auxCount, number=1;

int main(void){
    for (lineCount=1; lineCount<=5; lineCount++){
        for (auxCount=1; auxCount<=lineCount; auxCount++, number++){
            // imprime "number" durante "número de linha" vezes
            printf("%d ", number);
        }
        printf("\n"); // pula a linha depois de imprimir os números da linha
    }
    printf("\n");
    return 0;
}