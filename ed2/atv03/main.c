#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HORA 23
#define MAX_SEGMIN 59
#define STRLEN 128

typedef struct time
{
  int horas;
  int minutos;
  int segundos;
} t_time;

typedef struct timetable
{
  t_time key;
  char *value;
  struct timetable *prox;
} t_timetable;

typedef struct list
{
  t_timetable *data;
  int size;
} linked_list;

// Retorna:
// 1  se h1 >  h2
// 0  se h1 == h2
// -1 se h1 <  h2
int time_cmp(t_time h1, t_time h2)
{
  int segundos_t1 = (h1.horas * 60 * 60) + (h1.minutos * 60) + h1.segundos;
  int segundos_t2 = (h2.horas * 60 * 60) + (h2.minutos * 60) + h2.segundos;

  if (segundos_t1 == segundos_t2)
    return 0;
  if (segundos_t1 > segundos_t2)
    return 1;
  return -1;
}

int read_time(char *output, int limite_max)
{
  int time = -1;

  printf("%s - mín.: 0, máx.: %d\n", output, limite_max);
  while (time < 0 || time > limite_max)
  {
    scanf("%d", &time);
  }

  return time;
}

t_time new_time()
{
  t_time t;

  t.horas = read_time("Insira a hora", MAX_HORA);
  t.minutos = read_time("Insira os minutos", MAX_SEGMIN);
  t.segundos = read_time("Insira os segundos", MAX_SEGMIN);

  return t;
}

void get_string(char *value)
{
  printf("Insira o valor: ");

  setbuf(stdin, NULL);
  if (fgets(value, STRLEN, stdin))
  {
    value[strcspn(value, "\n")] = 0;
  }
}

t_timetable *new_timetable()
{
  char *value = malloc(sizeof(char) * STRLEN);
  get_string(value);

  t_timetable *t = malloc(sizeof(t_timetable));

  if (!t)
  {
    printf("Erro alocando memória\n");
    exit(1);
  }

  t->key = new_time();
  t->value = value;
  t->prox = NULL;

  return t;
}

// insere par key-value na tabela (remove elemento se valor for null)
void put(t_time key, char * val);

// valor armazenado com a chave key (null se key não existe)
char* get(t_time key);

// remove chave e seu valor da tabela
void delete(t_time key);

// existe um valor com a chave key?
int contains(t_time key);

// a tabela está vazia?
int is_empty();

// número de pares key-value armazenados na tabela
int size();

// menor chave armazenada
t_time min();

// maior chave armazenada
t_time max();

// maior chave armazenada menor ou igual à key
t_time floor(t_time key);

// menor chave armazenada maior ou igual à key
t_time ceiling(t_time key);

// número de chaves armazenadas menores do que key
int rank(t_time key);

// chave de rank igual a k
t_time select(int k);

// remove a menor chave
void delete_min();

// remove a maior chave
void delete_max();

// número de chaves armazenadas entre [lo..hi]
int size_range(t_time lo, t_time hi);

// chaves armazenadas entre [lo..hi]
t_time* keys(t_time lo, t_time hi);

int main(int argc, char **argv)
{
  t_timetable *t = new_timetable();

  printf("%s - %2d:%2d:%2d\n", t->value, t->key.horas, t->key.minutos, t->key.segundos);

  return 0;
}