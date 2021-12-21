// E19) Faça um programa que leia um número inteiro e apresente o valor correspondente em decimal,
// hexadecimal, octal e binário. Cada número em uma linha (respeite a ordem dos elementos).

#include <stdio.h>

int main()
{
    int n, bin, primeiroUm = 1;

    scanf("%d", &n);

    printf("%d\n%x\n%o\n", n, n, n);

    for (int i = 31; i >= 0; i--)
    {
        bin = (0x01 << i) & n;
        // Abaixo é uma validação para só exibir o número binário a partir do primeiro bit ativo (1)
        if (primeiroUm && bin)
        {
            printf("1");
            primeiroUm = 0;
        }
        else if (bin)
        {
            printf("1");
        }
        else if (!bin && !primeiroUm)
            printf("0");
    }
    printf("\n");

    return 0;
}