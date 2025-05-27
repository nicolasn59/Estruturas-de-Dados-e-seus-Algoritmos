#include "TABB_03.h"

TABB *cria(int raiz, TABB *left, TABB *right){
    TABB *novo = (TABB*) malloc(sizeof(TABB));
    novo->info = raiz;
    novo->esq = left;
    novo->dir = right;
    return novo;
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

static TABB *maximo(TABB *a) {
    while (a && a->dir) a = a->dir;
    return a;
}

static TABB *remove_no(TABB *a, int valor) {
    if (!a) return NULL;
    if (valor < a->info)
        a->esq = remove_no(a->esq, valor);
    else if (valor > a->info)
        a->dir = remove_no(a->dir, valor);
    else {
        // achou o nó a remover
        if (!a->esq) {
            TABB *temp = a->dir;
            free(a);
            return temp;
        }
        else if (!a->dir) {
            TABB *temp = a->esq;
            free(a);
            return temp;
        }
        else {
            TABB *pred = maximo(a->esq);
            a->info = pred->info;
            a->esq = remove_no(a->esq, pred->info);
        }
    }
    return a;
}

TABB *retira_impares(TABB *a) {
    if (!a) return NULL;
    a->esq = retira_impares(a->esq);
    a->dir = retira_impares(a->dir);
    if (a->info % 2 != 0) {
        printf("%d foi removido da arvore!\n", a->info);
        return remove_no(a, a->info);
    }
    return a;
}