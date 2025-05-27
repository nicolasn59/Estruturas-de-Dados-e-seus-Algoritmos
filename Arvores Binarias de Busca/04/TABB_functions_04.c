#include "TABB_04.h"

static TABB *cria(int raiz, TABB *left, TABB *right){
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

int qtd_elems_menores_N(TABB *a, int N){
    if (!a){
        return 0;
    }
    int contar_esq = qtd_elems_menores_N(a->esq, N);
    int contar_dir = qtd_elems_menores_N(a->dir, N);
    if (a->info < N){
        return (contar_esq + contar_dir + 1);
    }
    return (contar_esq + contar_dir);
}


int *mN(TABB *a, int N){
    int len_vetor = qtd_elems_menores_N(a, N);
    int *v = (int*) malloc(len_vetor * sizeof(int));
    int i=0;
    preencher_vetor(a, v, &i, N);
    return v;
}

static void preencher_vetor(TABB *a, int *v, int *i, int N){
    if (!a){
        return;
    }
    preencher_vetor(a->esq, v, i, N);
    if (a->info < N){
        v[*i] = a->info;
        (*i)++;
        preencher_vetor(a->dir, v, i, N);
    }
}
