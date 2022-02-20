struct _Lista
{
  // Dados poderia ser uma struct
  int dados;
  struct _Lista *prox;
};
// A Lista é um ponteiro de ponteiro
typedef struct _Lista *Lista;

Lista *criaLista();
void liberaLista(Lista *li);
int verificaListaVazia(Lista *li);
int verificaTamanhoLista(Lista *li);