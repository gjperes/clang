/* O que tira nota: 
- Alocação dinâmica incorreta
- Fluxo de execução dos controles de maneira inadequada
- Alocação sem liberação de memória correspondente

Critérios para a nota:
- Precedência -> N, L, S, O
1. Ler o arquivo texto e carregar a informação em memória
2. Posicionar o robô e fazer o percurso conforme precedência
3. Robô consegue encontrar a saída
*/

// TODO ESSENCIAL -> Receber de input do usuário a posição inicial do robô no labirinto, criar também uma ferramenta para
// verificar se o robô está preso e sem opções

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tamanho do mapa
#define LATERAL 8
#define ALTURA 8

// Define alguns parâmetros básicos para navegação no mapa
#define MURO 'M'
#define VAZIO ' '
#define START 'S'
#define DESTINO 'D'
#define CHECK 'x'

/**
 * @brief Nó de uma lista encadeada
 */
typedef struct _NODE {
    int linha;
    int coluna;
    struct _NODE *aponta;
} NODE;

/**
 * @brief Posição no topo da pilha encadeada
 */
typedef struct {
    NODE *topo; // Posição em memória do elemento no topo da pilha
} PILHA;

/**
 * @brief Aloca em memória e cria o nó para ser inserindo em uma pilha, e inclui esse nó no topo da pilha
 * 
 * @param p Recebe o endereço da pilha
 * @param linha Um dos valores do nó criado
 * @param coluna Um dos valores do nó criado
 */
void criaPilha(PILHA *p, int linha, int coluna) {
    NODE *novo;
    
    novo = (NODE *)malloc(sizeof(NODE));

    // Insere os dados no nó
    novo->linha = linha;
    novo->coluna = coluna;

    // O ponteiro do novo nó aponta para o antigo topo da pilha (penúltimo elemento)
    novo->aponta = p->topo;

    // Esse novo nó se torna o topo da pilha
    p->topo = novo;

}

/**
 * @brief Remove o elemento no topo da pilha, e libera o endereço de memória que estava reservado para tal elemento
 * 
 * @param p Recebe o endereço da pilha a ser removida
 */
void removePilha(PILHA *p) {
    NODE *topo = p->topo; // Nó auxiliar que aponta para o elemento no topo da pilha

    p->topo = topo->aponta; // O topo da pilha passa a ser o endereço do penúltimo elemento da pilha, apontado por esse nó
    free(topo); // Libera de memória o nó auxiliar
}

/**
 * @brief Verifica as rotas possíveis para o robô
 * 
 * @param pilha Endereço da pilha que irá armazenar a rota
 * @param mapa Matriz que contém o mapa do labirinto
 * @return int -- Nessa versão é obrigatório o mapa ter uma solução possível, o return será sempre 1
 */
int verifica(PILHA *pilha, char **mapa) {
    int i, j, aux1, aux2;
    int encontrouSaida = 0;

    do {
        i = pilha->topo->linha;
        j = pilha->topo->coluna;
        
        if( (i - 1 > -1) && (mapa[i-1][j] == VAZIO || mapa[i-1][j] == START) ) {
            i--;

            criaPilha(pilha, i, j);

            if(mapa[i][j] == START)
                encontrouSaida = 1;

            mapa[i][j] = CHECK;

        }
        else if( (j + 1 < LATERAL) && (mapa[i][j+1] == VAZIO || mapa[i][j+1] == START) ) {
            j++;

            criaPilha(pilha, i, j);

            if(mapa[i][j] == START)
                encontrouSaida = 1;

            mapa[i][j] = CHECK;
        }
        else if( (i + 1 < ALTURA) && (mapa[i+1][j] == VAZIO || mapa[i+1][j] == START) ) {
            i++;

            criaPilha(pilha, i, j);

            if(mapa[i][j] == START)
                encontrouSaida = 1;

            mapa[i][j] = CHECK;
        }
        else if( (j - 1 > -1) && (mapa[i][j-1] == VAZIO || mapa[i][j-1] == START) ) {
            j--;

            criaPilha(pilha, i, j);
            criaPilha(pilha, i, j);

            if(mapa[i][j] == START)
                encontrouSaida = 1;

            mapa[i][j] = CHECK;
        }
        else {
            printf("Opa! Encontrou uma parede! Linha:%2d Coluna:%2d\n", i, j);
            removePilha(pilha);
        }

        if(encontrouSaida)
            printf("\nEncontrou a saída na Linha:%2d Coluna:%2d\n", i, j);
        else
            printf("\nProcurando a saída na Linha:%2d Coluna:%2d\n", i, j);
    
        for(aux1=0; aux1 < ALTURA; aux1++) {

            for(aux2=0; aux2 < LATERAL; aux2++)
                printf("%c", mapa[aux1][aux2]);
        
            printf("\n");
        }

    } while(!encontrouSaida);

    return encontrouSaida;
}

int main(int argc, char *argv[]) {
    PILHA pilha;
    FILE *fp;
    int i, j, cont=1;
    char **mapa, buffer[8192];

    // Verifica se é possível criar || abrir arquivo do labirinto
    if ((fp=fopen("labirinto.txt", "r")) == NULL) {
        printf("Não foi possível ler o arquivo.");
        exit(0);
    }

    fseek(fp, 0L, SEEK_SET);
    mapa = (char **)malloc(sizeof(char *)*ALTURA); // Aloca dinamicamente a quantidade de linhas

    // Grava o mapa em memória
    for(i=0; i < ALTURA; i++) {
        // Aloca dinamicamente a quantidade de colunas da linha
        mapa[i] = (char *)malloc(sizeof(char)*(LATERAL + 1));

        fgets(buffer, 8192, fp);

        for(j=0; j < LATERAL; j++) {
            // Percorre a linha, gravando-a em memória
            mapa[i][j] = buffer[j];

            if(mapa[i][j] == DESTINO)
                criaPilha(&pilha, i, j);

            mapa[i][LATERAL] = '\0';
        }
    }
    fclose(fp);

    verifica(&pilha, mapa);
    printf("\nRota para sair do labirinto:\n");

    // Libera em memória a pilha - O QUE PODE SER MELHORADO: Editar o conteúdo para símbolos que representem o nível em que o robo acessou tal posição
    while(pilha.topo != NULL) {
        i = pilha.topo->linha;
        j = pilha.topo->coluna;

        removePilha(&pilha);
        printf("%2do movimento: L=%2d C=%2d\n", cont++, i, j);
    }

    printf("\n");

    // Desaloca a memória utilizada para gravar o mapa em memória
    for(i=0; i < ALTURA; i++) {

        for(j=0; j < LATERAL; j++)
            printf("%c", mapa[i][j]);
        
        free(mapa[i]);
        printf("\n");
    }

    free(mapa);
    return 0;
}