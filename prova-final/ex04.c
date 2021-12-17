// Faça um programa que leia um arquivo texto e apresente o número de linhas e palavras contidas no arquivo. 
// Considere qualquer termo delimitado por espaços, pontuação ou quebra de linha como delimitador das palavras.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// TODO bem importante -> simbolos inválidos continuos vão contar como 1 palavra, mesmo não sendo, exemplo:
// Resulta: " ," -> palavras = palavras + 2;

int main(){
    FILE *fp;
    char buffer[8192], *p;
    int linhas=0, palavras=0;

    if( (fp=fopen("texto1.txt", "r")) == NULL ) {
        printf("Erro lendo os arquivos");
        exit(0);
    }

    while(fgets(buffer, 8192, fp)) {
        p = buffer;
        linhas++;

        while(*p) {
            if (isalpha(*p)) // ele faz essa validação antes do loop abaixo para contar no COMEÇO de uma palavra válida
                palavras++;

            while(isalpha(*p)) // mantemos nesse loop enquanto for válido, para que as letras válidas seguintes não contem como palavras separadas
                p++;
            
            // saindo do loop, avançamos uma posição e refazemos o processo, até o fim da linha
            p++;
        }
    }

    printf("linhas=%4d\tpalavras=%6d\n", linhas, palavras); 

    fclose(fp);
    return 0;
}