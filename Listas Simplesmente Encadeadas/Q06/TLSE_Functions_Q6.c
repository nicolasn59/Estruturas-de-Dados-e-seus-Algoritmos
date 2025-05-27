#include "TLSE_Q6.h"

TLSE *alocaNo(){
    TLSE *no = (TLSE*) malloc(sizeof(TLSE));
    no->prox = NULL;
    return no;
}

TLSE *insereInicio(TLSE *l, int elem){
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


TLSE *i_p(TLSE *l){
    TLSE *l_copia = NULL, *atual;
    if (l){
        for (int i=0; i<2; i++){
            atual = l;
            while (atual != NULL){
                if (i == 0){
                    if (atual->info % 2 != 0){
                        l_copia = insereFinal(l_copia, atual->info);
                    }
                }
                else{
                    if (atual->info % 2 == 0){
                        l_copia = insereFinal(l_copia, atual->info);
                    }
                }
                atual = atual->prox;
            }
        }
        return l_copia;
    }
    return l_copia;
}
