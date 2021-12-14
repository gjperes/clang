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

    printf("Empilhando na pos: %d | %d\n", linha, coluna);
}

/**
 * @brief Remove o elemento no topo da pilha, e libera o endereço de memória que estava reservado para tal elemento
 * 
 * @param p Recebe o endereço da pilha a ser removida
 */
void removePilha(PILHA *p) {
    
    NODE *topo = p->topo; // Nó auxiliar que aponta para o elemento no topo da pilha
    int linha, coluna;

    p->topo = topo->aponta; // O topo da pilha passa a ser o endereço do penúltimo elemento da pilha, apontado por esse nó
    
    // aqui serve apenas para apresentação visual
    linha = topo->linha;
    coluna = topo->coluna;
    printf("Removido pos: %d | %d\n", linha, coluna);
    // fim apresentação visual

    free(topo); // Libera de memória o nó auxiliar
}

int verifica(PILHA *pilha, char **mapa){
    PILHA *p = pilha;
    int i, j;
    int saida = 0;

    do {
        i = pilha->topo->linha;
        j = pilha->topo->coluna;

        if(matriz[i][j] == START)
            saida = 1;
        else {

            // NORTE
            if( (i - 1 > -1) && (mapa[i-1][j] != MURO) && (mapa[i-1][j] != CHECK) ) {
                criaPilha(*p, (i-1), j);
                mapa[i-1][j] = CHECK;
                verifica(pilha, matriz);
            }

            // LESTE
            if( (j + 1 < LATERAL) && (mapa[i][j+1] != MURO) && (mapa[i][j+1] != CHECK) ) {
                criaPilha(*p, i, (j+1));
                mapa[i][j+1] = CHECK;
                verifica(pilha, matriz);
            } 

            // SUL
            if( (i + 1 < ALTURA) && (mapa[i+1][j] != MURO) && (mapa[i+1][j] != CHECK) ) {
                criaPilha(*p, (i+1), j);
                mapa[i+1][j] = CHECK;
                verifica(pilha, matriz);
            } 

            // OESTE
            if ( (j - 1 > -1) && (mapa[i][j-1] != MURO) && (mapa[i][j-1] != CHECK) ) {
                criaPilha(*p, i, (j-1));
                mapa[i][j-1] = CHECK;
                verifica(pilha, matriz);
            }
        }

    } while(!saida);
}

int main(int argc, char *argv[]) {
    PILHA pilha;
    FILE *fp;
    int i, j;
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

    // ALTERAR APENAS ESSA PARTE DO CÓDIG
    verifica();
    // ALTERAR APENAS ESSA PARTE DO CÓDIGO

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