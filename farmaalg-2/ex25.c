// E25) Faça um programa que leia dois valores inteiros (A e B) e apresente o resultado da operação de A elevado a B.

#include <stdio.h>

int main() {
    int a, b, res;

    scanf("%d", &a);
    scanf("%d", &b);

    if (!b) {
        res = 1;
    } else {
        res = a;
        for (int i=1; i < b; i++) {
            res = res * a;
        }
    }

    printf("%d\n", res);

    return 0;
}