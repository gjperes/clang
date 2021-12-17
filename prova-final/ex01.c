// MDC

#include <stdio.h>

int mdc(int num1, int num2) {
    int resultado;

    do {
        resultado = num1 % num2;

        num1 = num2;
        num2 = resultado;

    } while (resultado);

    return num1;
}

int main(){
    int n1, n2, i;

    scanf("%d %d", &n1, &n2);

    printf("%d\n", mdc(n1, n2));
}