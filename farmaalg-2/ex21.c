// E21) Faça um programa que leia 6 números que representem respectivamente os valores de hora1, minuto1, segundo1, hora2, minuto2 e segundo2.
// O programa deve verificar as entradas para que hora seja informada entre 0 e 23, minutos e segundos de 0 a 59.
// Por fim o programa deve mostrar a diferença entre as duas entradas (a 1a menos a 2a) na forma de horas : minutos : segundos.

// A solução atual é bem tosca, eu usei variáveis globais e funções bem mal feitas... preciso rever isso futuramente! (confesso estar com sono enquanto faço esse exercício)

#include <stdio.h>
#define qtd 2

int resHora, resMin, resSeg;

void valida_hora(int tempo[], int posi)
{
    do
    {
        scanf("%d", &tempo[posi]);
    } while (tempo[posi] > 23 || tempo[posi] < 0);
}

void valida_tempo(int tempo[], int posi)
{
    do
    {
        scanf("%d", &tempo[posi]);
    } while (tempo[posi] > 59 || tempo[posi] < 0);
}

int f_resHora(int hora1, int hora2)
{
    int res = hora1 - hora2;
    if (res > 0)
        return res;
    return res * (-1);
}

int f_resMin(int min1, int min2)
{
    int res = min1 - min2;
    if (res < 0)
    {
        resHora--;
        min1 += 60;
        return min1 - min2;
    }
    return res;
}

int f_resSeg(int seg1, int seg2)
{
    int res = seg1 - seg2;
    if (res < 0)
    {
        resMin--;
        seg1 += 60;
        return seg1 - seg2;
    }
    return res;
}

int main()
{
    int hora[qtd], minuto[qtd], segundo[qtd];

    for (int i = 0; i < qtd; i++)
    {
        valida_hora(hora, i);
        valida_tempo(minuto, i);
        valida_tempo(segundo, i);
    }

    resHora = f_resHora(hora[0], hora[1]);
    resMin = f_resMin(minuto[0], minuto[1]);
    resSeg = f_resSeg(segundo[0], segundo[1]);

    if (resMin < 0)
        resHora--;
    if (resHora < 0)
        resHora += 24;

    printf("%d:%d:%d\n", resHora, resMin, resSeg);

    return 0;
}