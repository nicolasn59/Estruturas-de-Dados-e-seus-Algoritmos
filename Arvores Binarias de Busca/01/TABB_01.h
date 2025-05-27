#include <stdio.h>
#include <stdlib.h>

typedef struct ab{
    int info;
    struct ab *esq, *dir;
} TABB;

TABB *inicializa(void);
TABB *insere(TABB *a, int elem);
void imprime_pre(TABB *a);
void libera(TABB *a);
TABB *maior(TABB *a);
