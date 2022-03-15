#ifndef CLANG_JOSEPH_H
#define CLANG_JOSEPH_H

#define TAM_NOME 50;

typedef struct _NodeSoldado NodeSoldado;
typedef struct _Cabecalho Cabecalho;

NodeSoldado* criarNode();
void inicializaLista(NodeSoldado **primeiroNode);
void inserirSoldado(NodeSoldado **primeiroNode, char[TAM_NOME] nomeSoldado);
int removerSoldado(NodeSoldado **primeiroNode, char[TAM_NOME] nomeSoldado);

// libera forçadamente a lista se não remover tudo
void liberaLista(NodeSoldado **primeiroNode); 

#endif //CLANG_JOSEPH_H
