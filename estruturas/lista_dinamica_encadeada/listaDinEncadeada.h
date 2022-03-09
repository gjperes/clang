// ED **Lista
typedef struct _Lista *Lista;

Lista *criaLista();

void liberaLista(Lista **li);

int verificaListaVazia(Lista **li);

int verificaTamanhoLista(Lista **li);