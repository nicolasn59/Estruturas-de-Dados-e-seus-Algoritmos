#include "TLSE_Q10.h"

static TLSE *alocaNo(){
    TLSE *no = (TLSE*) malloc(sizeof(TLSE));
    no->prox = NULL;
    return no;
}

void libera(TLSE *l) {
    TLSE *tmp;
    while (l) {
        tmp = l;
        l = l->prox;
        free(tmp);
    }
}

TLSE *insereFinal(TLSE *l, int elem){
    TLSE *novoNo = alocaNo();
    novoNo->info = elem;
    if (l){
        TLSE *aux = l;
        while (aux != NULL){
            if (aux->prox == NULL){
                aux->prox = novoNo;
                return l;
            }
            aux = aux->prox;
        }
    }
    l = novoNo;
    return l;
}

static TLSE *insereInicio(TLSE *l, int elem){
    TLSE *novoNo = alocaNo();
    novoNo->info = elem;
    if (l){
        TLSE *aux = l;
        l = novoNo;
        l->prox = aux;
        return l;
    }
    l = novoNo;
    return l;
}


void imprimeLista(TLSE *l){
    if (l){
        TLSE *aux = l;
        while (aux != NULL){
            printf("| %d | ", aux->info);
            aux = aux->prox;
        }
        printf("\n");
        return;
    }
    printf("LISTA VAZIA!\n");
}

static TLSE *copia_inversa(TLSE *l){
    if (l){
        TLSE *l_copia = NULL, *aux = l;
        while (aux != NULL){
            l_copia = insereInicio(l_copia, aux->info);
            aux = aux->prox;
        }
        return l_copia;
    }
    return NULL;
}

static int length(TLSE *l){
    TLSE *aux = l; 
    int len=0;
    while (aux != NULL){
        len++;
        aux = aux->prox;
    }
    return len;
}

static int igual(TLSE *l1, TLSE *l2){
    if ((l1 == NULL) && (l2 == NULL)){
        return 1;
    }
    else{
        if (length(l1) != length(l2)){
            return 0;
        }
        else{
            TLSE *aux1 = l1, *aux2 = l2;
            while (aux1 != NULL){
                if (aux1->info != aux2->info){
                    return 0;
                }
                aux1 = aux1->prox;
                aux2 = aux2->prox;
            }
            return 1;
        }
    }
}

int Contrario(TLSE *l1, TLSE *l2){
    printf("\n\n");
    imprimeLista(copia_inversa(l1));
    printf("\n");
    imprimeLista(l2);
    if (igual(copia_inversa(l1), l2)){
        return 1;
    }
    return 0;
}
