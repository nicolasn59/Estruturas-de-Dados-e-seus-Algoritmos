#include "TLSE_Q3.h"

TLSE * alocaNo(){
    TLSE *no = (TLSE*) malloc(sizeof(TLSE));
    no->prox = NULL;
    return no;
}

TLSE * insereFinal(TLSE *l, int elem){
    TLSE *novoNo = alocaNo();
    novoNo->info = elem;
    if (l){  // SE A LISTA EXISTIR
        TLSE *aux = l;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novoNo;
        return l;
    }
    l = novoNo;
    return l;  // APENAS 1 NÓ NA LISTA
}

void imprimeLista(TLSE *l){
    if (l){
        TLSE *aux = l;
        while (aux){
            printf("| %d |\t", aux->info);
            aux = aux->prox;
        }
        printf("\n");
    }
}

TLSE * desloca(TLSE *l, int n){
    if (n % 2 != 0){
        TLSE *salvaNo = l, *aux = l->prox, *antecessor =l;
        
        while (aux->prox != NULL){
            aux = aux->prox;
            antecessor = antecessor->prox;
        }
        
        l = aux;
        l->prox = salvaNo;
        antecessor->prox = NULL;
        return l;
    }
    else{
        TLSE *primeiroNo = l, *aux = l;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        l = l->prox;
        primeiroNo->prox = NULL;
        aux->prox = primeiroNo;
        return l;
    }
}
