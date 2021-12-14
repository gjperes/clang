// E21) Faça um programa que leia 6 números que representem respectivamente os valores de hora1, minuto1, segundo1, hora2, minuto2 e segundo2. 
// O programa deve verificar as entradas para que hora seja informada entre 0 e 23, minutos e segundos de 0 a 59. 
// Por fim o programa deve mostrar a diferença entre as duas entradas (a 1a menos a 2a) na forma de horas : minutos : segundos.

#include <stdio.h>
#define qtd 2

void valida_hora(int tempo[], int posi){

    do {
        scanf("%d", &tempo[posi]);
    } while (tempo[posi] > 23 || tempo[posi] < 0);

}

void valida_tempo(int tempo[], int posi){

    do {
        scanf("%d", &tempo[posi]);
    } while (tempo[posi] > 59 || tempo[posi] < 0);

}

int resultado(int v1,int v2){
    return (v1 - v2);
}

int main(){
    int hora[qtd], minuto[qtd], segundo[qtd];

    for (int i=0; i < qtd; i++) {
        valida_hora(hora, i);
        valida_tempo(minuto, i);
        valida_tempo(segundo, i);
    }

    printf("%d:%d:%d\n", resultado(hora[0], hora[1]), resultado(minuto[0], minuto[1]), resultado(segundo[0], segundo[1]));

    return 0;
}