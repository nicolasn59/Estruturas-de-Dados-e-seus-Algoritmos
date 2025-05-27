#include "TLSE_Q11.h"

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
    if(l){
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

static TLSE *copia(TLSE *l1, TLSE *l2){
    if (l1){
        TLSE *l_copia = NULL, *aux = l1;
        while (aux != NULL){
            l_copia = insereFinal(l_copia, aux->info);
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

TLSE *ordena(TLSE *l){
    TLSE *l_copia, *aux;
    l_copia = copia(l, l_copia);
    int len = length(l_copia);
    if (len > 1){
        for (int i=0; i < len; i++){
            aux = l_copia;
            for (int j=0; j < len-1; j++){
                if (aux->info > aux->prox->info){
                    int temp  = aux->info;
                    aux->info = aux->prox->info;
                    aux->prox->info = temp;
                }
                aux = aux->prox;
            }
        }
    }
    return l_copia;
}
