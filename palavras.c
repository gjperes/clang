#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    FILE *fp, *fpNovo;
    char buffer[8192], palavra[1024];
    char *p, *paux;

    if((fp = fopen(argv[1], "r")) == NULL) {
        printf("Nome do arquivo não encontrado! Verifique o parametro <nomedoarquivo.txt>");
        exit(0);
    }
    if((fpNovo = fopen("output.txt", "w")) == NULL) {
        printf("Não foi possível criar/abrir o arquivo de output!");
        fclose(fpNovo);
        exit(0);
    }

    while(fgets(buffer, 8192, fp) != NULL) {
    // enquanto tiver uma linha que possa ser bufferizada e captá-la via fgets a string, faça:
        p = buffer;

        while(*p) {
        // enquanto o Buffer não for \0:

            // while(*p && (*p < 'A' || (*p>'Z' && *p<'a') || *p>'z' )) 
            while(*p && !isalpha(*p))
            // enquanto for um símbolo NOT alfabeto, continue incrementando
                p++;
            if(!*p)
                break;
            
            paux = p;

            while(*paux && isalpha(*paux))
                paux++;
            
            memcpy(palavra, p, (paux- p));
            palavra[paux - p] = '\0'; // importante para evitar lixo de memória

            fprintf(fpNovo, "%s\n", palavra); // faz a cópia da palavra para o arquivo de output

            p = paux; // coloca o ponteiro que estava no começo da string no final, para seguir buscando uma string na linha
        }

    }

    fclose(fp);
    fclose(fpNovo);

    return 0;
}