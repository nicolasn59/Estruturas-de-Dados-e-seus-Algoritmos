#include "TLSE_Q8.h"

TLSE *alocaNo(){
    TLSE *no = (TLSE*) malloc(sizeof(TLSE));
    no->prox = NULL;
    return no;
}

TLSE * insereFinal(TLSE *l, int elem){
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

void imprimeLista(TLSE *l){
    if (l){
        TLSE *aux = l;
        while (aux != NULL){
            printf("| %d |\t", aux->info);
            aux = aux->prox;
        }
        printf("\n");
        return;
    }
    printf("Lista Vazia!\n");
}

int igual(TLSE *l1, TLSE *l2){
    if ((l1 == NULL) && (l2 == NULL)){
        return 1; 
    }
    else if ((l1 != NULL) && (l2 != NULL)){
        if (lenght(l1) != lenght(l2)){
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
        }
    }
    return 1;
}

int lenght(TLSE *l){
    TLSE *aux = l;
    int len = 0;
    while (aux != NULL){
        len++;
        aux = aux->prox;
    }
    return len;
}

TLSE *apagarLista(TLSE *l){
    while (l != NULL){
        TLSE *temp = l;
        l = l->prox;
        free(temp);
    }
    return NULL;
}
