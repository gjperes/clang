// E23) Escreva um programa na linguagem C que pede os coeficientes de uma equação do segundo grau e exibe as raízes da equação, 
// sejam elas reais ou complexas. Será necessário usar a função sqrt para calcular a raiz quadrada, 
// essa função está presente no cabeçalho math.h.

// // Complemente o código:

#include <stdio.h>
#include <math.h>

int main(void) {
    int a,b,c;
    double delta,x1,x2;

    scanf("%d %d %d",&a,&b,&c);
    // complemente o código
    if (a) {
        delta = (b*b) - (4 * (a*c));
        delta = sqrt(delta);

        x1 = (b*(-1)) + delta;
        x1 = x1 / (2 * a);

        x2 = (b*(-1)) - delta;
        x2 = x2 / (2 * a);
    }

    printf("%.2f\n%.2f\n",x1,x2);

    return 0;
}