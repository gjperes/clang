// Tipo de Dado Abstrato (TAD)
typedef struct Vetor Tipo_Lista;

// Tamanho máximo de valores que podem ser armazenados em dado da TAD
#define MAX_VETOR 5

// Cria uma lista estática
Tipo_Lista* criarLista(int dados[]);
// Desaloca de memória a lista estática
int liberarLista(Tipo_Lista *lista);
// Verifica se a lista está com o vetor de dados cheio
int verificarListaCheia(Tipo_Lista *lista, int tamanhoMax);
// Verifica se a lista está com o vetor de dados vazio
int verificarListaVazia(Tipo_Lista *lista);

int inserirInicioLista(Tipo_Lista *lista, Tipo_Lista *novoNode);

int inserirFinalLista(Tipo_Lista *lista, Tipo_Lista *novoNode);

int inserirMeioLista(Tipo_Lista *lista, Tipo_Lista *novoNode, int posicao);

int removerInicioLista(Tipo_Lista *lista);

int removerFinalLista(Tipo_Lista *lista);

int removerMeioLista(Tipo_Lista *lista, int posicao);

int consultarConteudoLista(Tipo_Lista *lista, int conteudo);

int consultarPosicaoLista(Tipo_Lista *lista, int posicao);

int imprimirLista(Tipo_Lista *lista);