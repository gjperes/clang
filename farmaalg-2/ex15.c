// E15) Faça um programa que leia dois números inteiros e apresente o MAIOR DIVISOR COMUM entre os dois números.


// usado o método de divisões sucessivas

#include <stdio.h>

int main() {

    int num1, num2, resto;

    scanf("%d", &num1);
    scanf("%d", &num2);

    if (num1 > num2) {

        do {

            resto = num1 % num2;

            num1 = num2;
            num2 = resto;

        } while(resto);

        printf("%d\n", num1);

    } else {

        do {

            resto = num2 % num1;

            num2 = num1;
            num1 = resto;

        } while(resto);

        printf("%d\n", num2);
    }

    return 0;
}