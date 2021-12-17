// Faça um programa que leia um número e apresente esse número na base binária. 
// O programa deverá apresentar a configuração dos bits para valores negativos e positivos.

#include <stdio.h>

int main(){
    int num, i, salvo;

    scanf("%d", &num);

    for(i = 31; i >= 0; i--) {
        salvo = (0x01 << i) & num;
        if(salvo ? printf("1") : printf("0"));
    }
    printf("\n");

    return 0;
}