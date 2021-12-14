// E19) Faça um programa que leia um número inteiro e apresente o valor correspondente em decimal,
// hexadecimal, octal e binário. Cada número em uma linha (respeite a ordem dos elementos).

#include <stdio.h>

int main(){
    int n;

    scanf("%d", &n);
    printf("%d\n%x\n%o\n", n, n, n);

    return 0;
}