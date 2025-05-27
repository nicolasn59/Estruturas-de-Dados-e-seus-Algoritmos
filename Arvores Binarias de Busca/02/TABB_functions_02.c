#include "TABB_02.h"

static TABB *cria(int raiz, TABB *left, TABB *right){
    TABB *novo = (TABB*) malloc(sizeof(TABB));
    novo->info = raiz;
    novo->esq = left;
    novo->dir = right;
}

TABB *insere(TABB *a, int elem){
    if (!a){
        a = cria(elem, NULL, NULL);
    }
    if (a->info > elem){
        a->esq = insere(a->esq, elem);
    }
    if (a->info < elem){
        a->dir = insere(a->dir, elem);
    }
    return a;
}

void imprime_pre(TABB *a){
    if (a){
        printf("%d ", a->info);
        imprime_pre(a->esq);
        imprime_pre(a->dir);
    }
}

void libera(TABB *a){
    if (a){
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
}

TABB *menor(TABB *a){
    if (!a){
        return NULL;
    }
    TABB *menor_esq = menor(a->esq);
    TABB *menor_no = a;
    if (menor_esq && menor_esq->info < menor_no->info){
        menor_no = menor_esq;
    }
    return menor_no;
}
