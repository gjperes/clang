// Tipo de Dado Abstrato (TAD)
typedef struct Vetor Tipo_Lista;

// Tamanho máximo de valores que podem ser armazenados em dado da TAD
#define MAX_VETOR 5

// TODO: Melhorar a descrição das funções
// Cria uma lista estática
Tipo_Lista* criarLista();

// Desaloca de memória a lista estática
void liberarLista(Tipo_Lista *lista);

// Retorna false só se a lista está vazia (sem dados)
int verificarListaCheia(Tipo_Lista *lista);

// Retorna false só se a lista tem algum dado
int verificarListaVazia(Tipo_Lista *lista);

// Insere o dado no ínicio da lista
int inserirInicioLista(Tipo_Lista *lista, int valor);

// Insere o dado no fim da lista
int inserirFinalLista(Tipo_Lista *lista, int valor);

int inserirMeioLista(Tipo_Lista *lista, Tipo_Lista *novoNode, int posicao);

int removerInicioLista(Tipo_Lista *lista);

int removerFinalLista(Tipo_Lista *lista);

int removerMeioLista(Tipo_Lista *lista, int posicao);

int consultarConteudoLista(Tipo_Lista *lista, int conteudo);

int consultarPosicaoLista(Tipo_Lista *lista, int posicao);

int imprimirLista(Tipo_Lista *lista);