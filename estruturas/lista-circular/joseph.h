#ifndef CLANG_JOSEPH_H
#define CLANG_JOSEPH_H

typedef struct Soldado Node;

Node* criarSoldado();
void criarListaSoldados(char *nomes, Node **soldados);
void definirSoldado(Node **soldados, char *nomeInicial, int contagem);
char[] removerSoldado(Node **soldadoAnterior, Node **soldado);

#endif //CLANG_JOSEPH_H
