// Faça um programa que apresente os números primos menores que 100.
// TODO - pode melhorar, e MUITO, o código tá tosco

#include <stdio.h>
short int number;

int main(void){
    for (number=0; number<=100; number++){
        if (number==1 || number==2 || number==3 || number==5 || number==7 || number==11 || number==13){
            // exceções primos
            printf("%2d", number);
            printf("\n");
        }
        else if (number % 2 == 0 || number % 3 == 0 || number % 5 == 0 || number % 7 == 0 || number % 11 == 0 || number % 13 == 0){}
        else{
            printf("%2d", number);
            printf("\n");
        }
    }
}