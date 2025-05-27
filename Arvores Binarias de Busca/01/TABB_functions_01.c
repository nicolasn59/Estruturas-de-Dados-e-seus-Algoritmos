#include "TABB_01.h"

TABB *inicializa(void){
    return NULL;
}

static TABB *cria(int raiz, TABB *left, TABB *right){
    TABB *novo = (TABB*) malloc(sizeof(TABB));
    novo->info = raiz;
    novo->esq = left;
    novo->dir = right;
    return novo;
}

TABB *insere(TABB *a, int elem){
    if (!a){
       return cria(elem, NULL, NULL);
    }
    if (a->info > elem){
        a->esq = insere(a->esq, elem);
    }
    else if (a->info < elem){
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

TABB *maior(TABB *a){
    if (!a){
        return NULL;
    }
    TABB *maior_elem = a;
    TABB *maior_dir = maior(a->dir);
    if (maior_dir && maior_dir->info > maior_elem->info){
        maior_elem = maior_dir;
    }
    return maior_elem;
}

/*
TABB *maior(TABB *a){
    if (!a){
        return NULL;
    }
    while (a->dir){
        a = a->dir;
    }
    return a;
}
*/