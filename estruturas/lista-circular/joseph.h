#define TAM_NOME 1

typedef struct _NodeSoldado NodeSoldado;
typedef struct _Cabecalho Cabecalho;

void inicializaLista(Cabecalho *Lista);
NodeSoldado* criarNode();
void inserirSoldado(Cabecalho *Lista, char nomeSoldado[TAM_NOME]);
int removerSoldado(Cabecalho *Lista, char nomeSoldado[TAM_NOME]);

// libera forçadamente a lista se não remover tudo
void liberaLista(Cabecalho *Lista);