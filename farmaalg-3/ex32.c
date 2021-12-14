#include <stdio.h>
#define TAM 100

// minha solução, bem torta... a que o professor passou em aula é BEM mais curta, mas não entendi legal
int mystrcmp(char *inputA, char *inputB){
    char *a = inputA;
    char *b = inputB;
    int res=0;

    while (*a) {

        if(*a != *b) {
            res = ((int)*a - (int)*b);
            break;
        }
        
        a++;
        b++;
    }
    res = ((int)*a - (int)*b);

    if (res == 0) {
        return 0;
    }
    else if (res > 0) {
        return 1;
    }
    return (-1);
}

int main(){
    char inputA[TAM];
    char inputB[TAM];

    scanf("%s", inputA);
    scanf("%s", inputB);

    printf("%d\n", mystrcmp(inputA, inputB));

    return 0;
}