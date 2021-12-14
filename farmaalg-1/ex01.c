// Faça um programa que apresente os números de 1 a 10, sendo que cada número deve ser
// impresso em uma linha e os números ímpares deslocados (\t) a direita.

#include <stdio.h>

short int count;

int main(void){
    for(count = 1; count <= 10; count++){
        if (count % 2 == 0){
            printf("%2d \n", count); // %d - numeros int base decimal
        }
        else{
            printf("\t %2d \n", count);
        }
    }
    printf("\n");
    return 0;
}