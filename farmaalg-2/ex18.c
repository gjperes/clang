// FUP que remova 0 a esquerda de uma string

#include <stdio.h>

void retira(char *texto){
    char *p = texto;
    char *proximo = p;

    while(*p) {
        if(*p == '0'){
            *p = "";
        }
        p++;

        if(*p != '0'){
            break;
        }
    }
}

int main(){
    char texto[50];

    scanf("%s", texto);

    retira(texto);
    printf("%s", texto);

    return 0;
}