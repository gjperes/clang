// E31) Faça um programa que leia DUAS string (A e B) com até 100 símbolos cada, 
// concatene o conteúdo da String B na string A e apresente o conteúdo da String A. 

// Não deverá fazer uso da função strcat ou strcpy.

#include <stdio.h>
#define TAM 100

int mystrcat(char *textoA, char *textoB){
    char *a = textoA;
    char *b = textoB;

    // set final da StringA
    while(*a) {
        a++;
    }

    // a = (a - 1); OBS*: // necessário se receber a string via fgets

    // strcpy
    while(*b) {
        *a = *b;
        a++;
        b++;
    }
    *a = *b;
   
    return (int)(b - textoB); // retorna a quantidade que foi copiada para o final da stringA
}

int main(){
    char strA[TAM], strB[TAM];

    // fgets(strA, TAM, stdin);
    // fgets(strB, TAM, stdin);
    scanf("%s", strA);
    scanf("%s", strB);

    mystrcat(strA, strB);

    printf("%s\n", strA);
}