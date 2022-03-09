// ED **Lista
typedef struct Bloco Node;

void iniciarLista(Node **noInicial);

void liberarLista(Node **noInicial);

Node *criaNode();

void inserirFinalLista(Node **noInicial, int num);

void inserirInicioLista(Node **noInicial, int num);

/**
 * Remove um item do início da lista, retorna bool e salva o dado removido em uma variável global
 * @param noInicial Ponteiro do nó inicial
 * @param retorno Valor removido
 * @return Boolean: sucesso ou não da operação
 */
int removerInicioLista(Node **noInicial, int *retorno);

int removerFinalLista(Node **noInicial, int *retorno);

void imprimirLista(Node *noInicial);

int verificarTamanhoLista(Node *noInicial);

int verificarListaVazia(Node *noInicial);

/**
 * Recebe a posição que deseja se verificar
 * @param noInicial Ponteiro que aponta para o primeiro nó
 * @param posicao Posição que deseja se verificar
 * @param retorno Retorna o dado obtido na posição encontrada
 * @return Bool -> Se tiver sucesso em acessar a posição desejada: True; else: False
 */
int consultarPosicaoLista(Node *noInicial, int posicao, int *retorno);

int consultarElementoLista(Node *noInicial, int elemento, int *retorno);
