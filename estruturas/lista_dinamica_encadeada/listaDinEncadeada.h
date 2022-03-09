// ED **Lista
typedef struct Bloco Node;

void iniciaLista(Node **no);

Node *criaNode();

void insereFinalLista(Node **noInicial, int num);

void insereInicioLista(Node **noInicial, int num);

/**
 * Remove um item do início da lista, retorna bool e salva o dado removido em uma variável global
 * @param noInicial Ponteiro do nó inicial
 * @param retorno Valor removido
 * @return Boolean: sucesso ou não da operação
 */
int removeInicioLista(Node **noInicial, int *retorno);

void imprimirLista(Node *noInicial);