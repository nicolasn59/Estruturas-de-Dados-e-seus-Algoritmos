#include <stdio.h>
#include <stdlib.h>

typedef struct ab{
    int info;
    struct ab *esq, *dir;
} TABB;

TABB *cria(int raiz, TABB *left, TABB *right);
TABB *insere(TABB *a, int elem);
void imprime_pre(TABB *a);
void libera(TABB *a);
TABB *retira_impares(TABB *a);
