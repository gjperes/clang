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

void imprimirLista(Node *noInicial);

int verificarTamanhoLista(Node *noInicial);