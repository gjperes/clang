// Tipo de Dado Abstrato (TAD)
typedef struct Vetor Tipo_Lista;

// Tamanho máximo de valores que podem ser armazenados em dado da TAD
#define MAX_VETOR 5

// TODO: Melhorar a descrição das funções

/** Cria uma nova lista e aloca ela em memória
 *  @return Retorna a nova lista
 */
Tipo_Lista* criarLista();

/** Desaloca de memória a lista estática
 * @param lista Lista que será desalocada
 */
void liberarLista(Tipo_Lista *lista);

/** Verifica se a lista está cheia
 * @param lista Lista para verificar
 * @return Lista Cheia ? True : False *Se NULL retorna -1
 */
int verificarListaCheia(Tipo_Lista *lista);

/** Verifica se a lista está vazia
 * @param lista Lista para verificar
 * @return Lista Vazia ? True : False *Se NULL retorna -1
 */
int verificarListaVazia(Tipo_Lista *lista);

/** Insere o dado no início da lista (posição 0)
 * @param lista Lista para verificar
 * @param valor Valor a ser inserido na lista
 * @return Sucesso na operação ? True : False
 */
int inserirInicioLista(Tipo_Lista *lista, int valor);

/** Insere o dado no final da lista
 * @param lista Lista para verificar
 * @param valor Valor a ser inserido na lista
 * @return Sucesso na operação ? True : False
 */
int inserirFinalLista(Tipo_Lista *lista, int valor);

int inserirMeioLista(Tipo_Lista *lista, Tipo_Lista *novoNode, int posicao);

int removerInicioLista(Tipo_Lista *lista);

int removerFinalLista(Tipo_Lista *lista);

int removerMeioLista(Tipo_Lista *lista, int posicao);

int consultarConteudoLista(Tipo_Lista *lista, int conteudo);

int consultarPosicaoLista(Tipo_Lista *lista, int posicao);

int imprimirLista(Tipo_Lista *lista);