// E30) Faça um programa que leia uma string com até 1000 símbolos e apresente o tamanho da string. Não deverá fazer uso da função strlen.

#include <stdio.h>
#define TAM 1000

int mystrlen(char *texto){
    char *t = texto; // ponteiro que aponta para o endereço do vetor

    while(*t)
        t++;

    return ((int)(t - texto) - 1); // retorna o tamanho -1 do char '\0'
}

int main(){
    char texto[TAM];

    fgets(texto, TAM, stdin);
    printf("%d\n", mystrlen(texto));

    return 0;
}