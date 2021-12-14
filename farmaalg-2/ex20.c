// E20) Faça um programa que apresente um “menu com 4 opções”, leia um número inteiro entre 1 e 4 
// indicando a opção do menu e para cada valor lido imprima, correspondentemente, as frases “opção 1”, “opção 2”, “opção 3”, “opção 4”. 
// Use o comando switch para resolver esse exercício. O programa encerra quando foi escolhido a opção 4, 
// nas demais condições deverá apresentar o menu novamente e ler uma nova opção.
// Sempre termine as strings com quebra de linha.

// Exemplo:
// output inicial:
// 1 - Opcao 1
// 2 - Opcao 2
// 3 - Opcao 3
// 4 - Opcao 4

// input
// 1
// 4

// output
// Opcao 1
// Opcao 4

#include <stdio.h>

int main(){
    int selec, boole=0;

    do {
    
    printf("1 - Opcao 1\n2 - Opcao 2\n3 - Opcao 3\n4 - Opcao 4\n");
    scanf("%d", &selec);
    
        switch(selec) {
            case 1:
                printf("Opcao 1");
                break;
            case 2:
                printf("Opcao 2");
                break;
            case 3:
                printf("Opcao 3");
                break;
            case 4:
                printf("Opcao 4");
                boole = 1;
                break;
            default:
                break;
        }

    printf("\n");

    } while(!boole);

    return 0;
}