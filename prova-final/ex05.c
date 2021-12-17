// Fala um programa que leia dois arquivos textos (A e B) e 
// crie um arquivo C de forma que as linhas dos arquivos A e B fiquem intercaladas no arquivo C. 
// Iniciando com a primeira linha do arquivo A.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *f1, *f2;
    char buffer[8192], *linha;
    int continua=1;

    if( ( (f1=fopen("texto1.txt", "r")) == NULL ) || ( (f2=fopen("texto2.txt", "r")) == NULL) ) {
        printf("Erro lendo os arquivos");
        exit(0);
    }   

    do {

        if(fgets(buffer, 8192, f1))
            linha = buffer;
        while(*linha) {
            printf("%c", *linha);
            linha++;
        }
        printf("\n");

        if(fgets(buffer, 8192, f2))
            linha = buffer;
        while(*linha) {
            printf("%c", *linha);
            linha++;
        }
        printf("\n");

        if (fgets(buffer, 8192, f1) == NULL && fgets(buffer, 8192, f2) == NULL)
            continua = 0;

    } while( continua );

    fclose(f1);
    fclose(f2);

    return 0;
}