typedef struct _Node {
    int dado;
    struct _Node *prox, *ant;
} Node;

typedef struct _Header {
    int tamanhoLista;
    Node *primeiroNode, *ultimoNode;
} Header;

void iniciar_header(Header *Lista);
Node cria_node();
int inserir_inicio_lista(Header *Lista, int dado);
int inserir_final_lista(Header *Lista, int dado);
int remover_inicio_lista(Header *Lista);
int remover_final_lista(Header *Lista);
void imprimir_lista(Header *Lista);
void liberar_lista(Header *Lista);

