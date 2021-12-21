// E12) Faça uma função setBit que receba dois parâmetros (nro e bit), 
// a função deve modificar o valor de nro de tal forma que o n-bit seja modificado para 1
// e retornar o novo valor.

#include <stdio.h>

int resetBit(int nro, int bit) {
    // complemente o código
    for (int i=31; i >= 0; i--)
        bit = 0x01 << i || nro;
    
    return bit;
}

int main(void) {

    int num,bit;

    scanf("%d %d",&num,&bit);
    printf("%d\n",resetBit(num,bit));

    return 0;
}
