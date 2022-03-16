#define TAM_NOME 1
#define MAX_SOLDADOS 5

typedef struct _NodeSoldado {
    char dado[TAM_NOME];
    struct _NodeSoldado *prox;
} NodeSoldado;

typedef struct _Header {
    int tamanhoLista;
    NodeSoldado *primeiroNode;
} Header;

void inicializaLista(Header *Lista);
NodeSoldado* criarNode();
void inserirSoldado(Header *Lista, char nomeSoldado[TAM_NOME]);
int removerSoldado(Header *Lista, char nomeSoldado[TAM_NOME]);

// libera forçadamente a lista se não remover tudo
void liberaLista(Header *Lista);