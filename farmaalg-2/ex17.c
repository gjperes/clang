// E17) Faça uma função que receba um vetor de char e um número e
// retorne no vetor o valores ‘0’ e ‘1’ correspondente ao valor binário de cada posição do número.
// Considere números de até 32 bits. (Considere o vetor com 33 posições).

#include <stdio.h>

void func(char vet[], int num)
{
    int bin;
    for (int i = 0; i < 32; i++)
    {
        if ((0x01 << i) & num)
            vet[31 - i] = '1';
        else
            vet[31 - i] = '0';
    }
    vet[32] = '\0';
}

int main(void)
{
    int num;
    char str[33];

    scanf("%d", &num);

    func(str, num);

    printf("%s\n", str);

    return 0;
}