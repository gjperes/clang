// E16) Faça um programa que apresente (imprima com %x os resultados das expressões):
// a) O valor hexadecimal do resultado do operador ~0x55
// b) O valor hexadecimal do resultado da operação 0x09 << 2
// c) O valor hexadecimal do resultado da operação 0x09 >> 2
// d) O valor hexadecimal do resultado da operação 0xFF >> 2
// e) O valor hexadecimal do resultado da operação 0xFF << 2

// output esperado:
// a) ffffffaa
// b) 24
// c) 2
// d) 3f
// e) 3fc

#include <stdio.h>

int main(){
    
    printf("%x\n", ~85);
    printf("%x\n", (9 << 2));
    printf("%x\n", (9 >> 2));
    printf("%x\n", (255 >> 2));
    printf("%x\n", (255 << 2));

    return 0;
}