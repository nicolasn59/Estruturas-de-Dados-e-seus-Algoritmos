#include "TAB_Q01.h"

TAB *inicializa_ab(){
    return NULL;
}

TAB *cria(int raiz, TAB *sae, TAB *sad){
    TAB *novo = (TAB*) malloc(sizeof(TAB));
    novo->info = raiz;
    novo->esq = sae;
    novo->dir = sad;
    return novo;
}

void imprime_pre(TAB *a){
    if (!a) return;
    printf("%d ", a->info);
    imprime_pre(a->esq);
    imprime_pre(a->dir);
}

void libera(TAB *a){
    if (!a) return;
    libera(a->esq);
    libera(a->dir);
    free(a);
}

TAB *copia(TAB *a){
    if (!a){  // Verifica o nó da árvore que será copiada
        return NULL;
    }
    TAB *novaAb = (TAB*) malloc(sizeof(TAB)); // Alocando um nó para folha da árvore cópia
    novaAb->info = a->info; 
    novaAb->esq = copia(a->esq); // Acessa o nó esquerdo até encontrar NULL
    novaAb->dir = copia(a->dir); // Acessa o nó esquerdo até encontrar NULL
    return novaAb;
}
