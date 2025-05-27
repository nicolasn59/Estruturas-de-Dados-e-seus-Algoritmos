#include "TLSE_Q12.h"

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

void ordena(TLSE *l1){  // Não é preciso fazer passagem por referência, pois estamos modificando os valores da lista (*l1 aponta para o endereço de memória)
    TLSE *i, *j;
    i = l1;
    while (i){  // Enquanto "i" existir
        j = l1;
        while (j->prox){  // Enquanto "j->prox" existir
            if (j->info > j->prox->info){
                int temp = j->info;
                j->info = j->prox->info;
                j->prox->info = temp;
            }
            j = j->prox;
        }
        i = i->prox;
    }
}
