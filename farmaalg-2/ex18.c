// Remova os 0 à esquerda da string do programa anterior (ex17)

#include <stdio.h>

void func(char vet[], int num)
{
    char *c, aux[33];
    int i;

    for (i = 0; i < 32; i++)
    {
        if ((0x01 << i) & num)
            aux[31 - i] = '1';
        else
            aux[31 - i] = '0';
    }
    aux[32] = '\0';

    c = aux;

    while (*c == '0')
    {
        c++;
    }

    i = 0;
    while (*c != '\0')
    {
        if (*c == '1')
            vet[i] = '1';
        else
            vet[i] = '0';
        c++;
        i++;
    }
    vet[i] = '\0';
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