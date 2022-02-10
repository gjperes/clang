/**
 * @file lista_sequencial.h
 * @author Gabril
 * @brief 
 * @version 0.1
 * @date 2022-02-09
 */

// Tamanho máximo de valores que podem ser armazenados em dado da TAD
#define MAX_VETOR 5

// Tipo de Dado Abstrato (TAD)
typedef struct Vetor Tipo_Lista;

/**
 * @brief Cria uma lista estática
 * 
 * @param dados Vetor que armaneza os dados da TAD
 * @return Tipo_Lista* Retorna a lista criada
 */
Tipo_Lista* criarLista(int dados[]);

/**
 * @brief Desaloca de memória a lista estática
 * 
 * @param lista Recebe a lista a ser desalocada
 * @return int Retorna tipo bool confirmando resultado da ação (Sucesso - 1 / Erro - 0)
 */
int liberarLista(Tipo_Lista *lista);

/**
 * @brief Verifica se a lista está com o vetor de dados cheio
 * 
 * @param lista Lista a ser verificada
 * @param tamanhoMax Tamanho máximo do vetor de dados
 * @return int Retorna tipo bool confirmando resultado (True - 1 / False - 0)
 */
int verificarListaCheia(Tipo_Lista *lista, int tamanhoMax);

/**
 * @brief Verifica se a lista está com o vetor de dados vazio
 * 
 * @param lista Lista a ser verificada
 * @return int Retorna tipo bool confirmando resultado (True - 1 / False - 0)
 */
int verificarListaVazia(Tipo_Lista *lista);


int inserirInicioLista(Tipo_Lista *lista, Tipo_Lista *novoNode);


int inserirFinalLista(Tipo_Lista *lista, Tipo_Lista *novoNode);


int inserirMeioLista(Tipo_Lista *lista, Tipo_Lista *novoNode, int posicao);


int removerInicioLista(Tipo_Lista *lista);


int removerFinalLista(Tipo_Lista *lista);


int removerMeioLista(Tipo_Lista *lista, int posicao);


int consultarConteudoLista(Tipo_Lista *lista, int conteudo);


int consultarPosicaoLista(Tipo_Lista *lista, int posicao);


int imprimirLista(Tipo_Lista *lista);