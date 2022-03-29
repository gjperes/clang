typedef struct _Node {
    int dado;
    struct _Node *prox, *ant;
} Node;

typedef struct _Header {
    int tamanhoLista;
    Node *primeiroNode, *ultimoNode;
} Header;

Node criaNode();
void inserirInicioLista(Header *Lista, int dado);
void inserirFinalLista(Header *Lista, int dado);
int removerInicioLista(Header *Lista);
int removerFinalLista(Header *Lista);
void imprimirLista(Header *Lista);
void liberarLista(Header *Lista);

