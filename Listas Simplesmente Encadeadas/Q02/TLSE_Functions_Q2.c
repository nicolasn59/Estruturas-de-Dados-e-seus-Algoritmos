#include "TLSE_Q2.h"

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


TLSE * inverte(TLSE *l){
    if (l == NULL){
        printf("LISTA VAZIA!\n");
        return l;
    }
    else{
        //  ESSA PARTE IRÁ COPIAR A LISTA 1(l) PARA A LISTA 2(l2)
        TLSE *l2 = NULL; // CABEÇA DA LISTA 2
        TLSE *aux = l; 
        while (aux != NULL){
            l2 = insereFinal(l2, aux->info); // CADA NÓ DA LISTA 2 IRÁ RECEBER O MESMO VALOR DA LISTA 1
            aux = aux->prox; // ATUALIZA PARA O PRÓXIMO NÓ DA LISTA 1 
        }

        TLSE *atual = l2, *antecessor=NULL, *sucessor=NULL;
        while (atual != NULL){ 
            sucessor = atual->prox;  // SUCESSOR VAI PARA O PRÓXIMO NÓ
            atual->prox = antecessor;  // O ENDEREÇO DO NÓ ATUAL VAI APONTAR PARA O ANTECESSOR, ONDE INICIALMENTE É NULL
            antecessor = atual;  // ANTECESSOR VAI PARA O NÓ ATUAL
            atual = sucessor;  // POR FIM, O NÓ ATUAL É ATUALIZADO PARA O PRÓXIMO NÓ
        }
        l2 = antecessor; // APÓS A ITERAÇÃO O ANTECESSOR ESTARÁ NO ÚLTIMO NÓ DA LISTA
        return l2;
    }
}

