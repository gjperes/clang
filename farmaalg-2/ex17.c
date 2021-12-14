// E17) Faça uma função que receba um vetor de char e um número e 
// retorne no vetor o valores ‘0’ e ‘1’ correspondente ao valor binário de cada posição do número. 
// Considere números de até 32 bits. (Considere o vetor com 33 posições).

#include <stdio.h>

void func(char vet[], int num) {
// complemente o código
    char *p = vet;

    while(*p){
        p++;
    }

    
}

int main(void) {
    int num;
    char str[33];

    scanf("%d",&num);

    func(str,num);

    printf("%s\n",str);

    return 0;
}