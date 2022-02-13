// Tipo de Dado Abstrato (TAD)
typedef struct Vetor Tipo_Lista;

// Tamanho máximo de valores que podem ser armazenados em dado da TAD
#define MAX_VETOR 5

/** Cria uma nova lista e aloca ela em memória
 *  @return Retorna a nova lista
 */
Tipo_Lista *criarLista();

/** Desaloca de memória a lista estática
 * @param lista Lista que será desalocada
 */
void liberarLista(Tipo_Lista *lista);

/** Verifica se a lista está cheia, se cheia -> TRUE
 * @param lista Lista para verificar
 * @return Lista Cheia ? True : False *Se NULL retorna -1
 */
int verificarListaCheia(Tipo_Lista *lista);

/** Verifica se a lista está vazia, se vazia -> TRUE
 * @param lista Lista para verificar
 * @return Lista Vazia ? True : False *Se NULL retorna -1
 */
int verificarListaVazia(Tipo_Lista *lista);

/** Insere o dado no início da lista (posição 0)
 * @param lista Lista para inserir
 * @param valor Valor a ser inserido na lista
 * @return Sucesso na inserção do valor ? True : False
 */
int inserirInicioLista(Tipo_Lista *lista, int valor);

/** Insere o dado no fim da lista
 * @param lista Lista para inserir
 * @param valor Valor a ser inserido na lista
 * @return Sucesso na inserção do valor ? True : False
 */
int inserirFinalLista(Tipo_Lista *lista, int valor);

/** Insere o dado de maneira ordenada na lista
 * @param lista Lista para inserir
 * @param valor Valor a ser inserido na lista
 * @return Sucesso na inserção do valor ? True : False
 */
int inserirOrdenadoLista(Tipo_Lista *lista, int valor);

/** Remove o primeiro elemento da lista, posição 0
 * @param lista Lista que terá a remoção do elemento
 * @return Sucesso na remoção ? True : False
 */
int removerInicioLista(Tipo_Lista *lista);

/** Remove o último elemento da lista
 * @param lista Lista que terá a remoção do elemento
 * @return Sucesso na remoção ? True : False
 */
int removerFinalLista(Tipo_Lista *lista);

/** Remove um elemento em específico da lista, se existente
 * @param lista Lista que terá a remoção do elemento
 * @param valor Valor que deverá ser removido se existente na lista
 * @return Sucesso na remoção ? True : False
 */
int removerMeioLista(Tipo_Lista *lista, int valor);

/** Verifica se um determinado valor existe na lista
 * @param lista Lista para verificação
 * @param valor Valor a ser identificado na lista
 * @return Encontrou o elemento ? True : False
 */
int consultarConteudoLista(Tipo_Lista *lista, int valor);

/** Verifica se a lista é de tamanho igual ou maior que a posição indicada
 * @param lista Lista para verificação
 * @param posicao Posição a ser validade
 * @return A posição existe na lista ? True : False
 */
int consultarPosicaoLista(Tipo_Lista *lista, int posicao);

/** Imprime no console a lista
 * @param lista Lista a ser impressa
 * @return A lista foi impressa com sucesso ? True : False
 */
int imprimirLista(Tipo_Lista *lista);