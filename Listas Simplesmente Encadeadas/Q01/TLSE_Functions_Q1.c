#include "TLSE_Q1.h"

static TLSE * alocaNo(){
    TLSE *no;
    no = (TLSE*) malloc(sizeof(TLSE));
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

TLSE * insereFinal(TLSE *l, int elem){
    TLSE *novoNo = alocaNo();
    novoNo->info = elem;
    if (l == NULL){
        l = novoNo;
        return l;
    }
    else{
        TLSE *aux = l;
        while (aux != NULL){
            if (aux->prox == NULL){
                aux->prox = novoNo;
                return l;
            }
            aux = aux->prox;
        }
    }
    return l;
}


void imprimeLista(TLSE *l){
    if (l == NULL){
        printf("Lista Vazia!\n");
        return;
    }
    else{
        TLSE *aux = l;
        while (aux != NULL){
            printf("| %d |\t", aux->info);
            aux = aux->prox;
        }
        printf("\n");
    }
}


void inverte(TLSE **l){
    if (*l == NULL){
        printf("LISTA VAZIA!\n");
        return;
    }
    else{
        TLSE *atual = *l, *antecessor=NULL, *sucessor=NULL;
        while (atual != NULL){ 
            sucessor = atual->prox;  // SUCESSOR VAI PARA O PRÓXIMO NÓ
            atual->prox = antecessor;  // O ENDEREÇO DO NÓ ATUAL VAI APONTAR PARA O ANTECESSOR, ONDE INICIALMENTE É NULL
            antecessor = atual;  // ANTECESSOR VAI PARA O NÓ ATUAL
            atual = sucessor;  // POR FIM, O NÓ ATUAL É ATUALIZADO PARA O PRÓXIMO NÓ
        }
        *l = antecessor; // APÓS A ITERAÇÃO O ANTECESSOR ESTARÁ NO ÚLTIMO NÓ DA LISTA
    }
}
