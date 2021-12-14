// Faça um programa que apresente a tabela ASCII (0 a 255), no formato de 16 linhas por 16 
// colunas, tendo a 1a linha e a 1a coluna rotulada com o valor em hexadecimal de 0 a F. A 
// primeira célula terá o símbolo com código 0, a segunda com código 1 e assim por diante.

// Obs: Inicialmente, substitua os valores < 32 por 32, para evitar a impressão dos códigos de 
// controle.

// ideia -> 2 laços (linha e coluna), no laço coluna incrementar o número do caracter ascii

#include <stdio.h>

short int codAscii=0, line, column, hexaLine=48, hexaColumn;

int main(void){
    for (line=0; line<16; line++){
        hexaColumn = 48;
        for (column=0; column<16; column++){
            printf(" %c%c: ", hexaLine, hexaColumn);
            if (codAscii<32){
                printf("%c", 32);
            }
            else{
                printf("%c", codAscii);
            }
            codAscii++;
            if (hexaColumn<57 || hexaColumn>64){hexaColumn++;}
            else if (hexaColumn=57){hexaColumn = 65;}
        }
        printf("\n");
        if (hexaLine<57 || hexaLine>64){hexaLine++;}
        else if (hexaLine=57){hexaLine = 65;}
    }
    printf("\n");
    return 0;
}