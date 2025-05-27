#include "TAVL_02.h"

void imprime_sim(TAVL *a){
    if (a){
        imprime_sim(a->esq);
        printf("%d ", a->info);
        imprime_sim(a->dir);
    }
}

void libera(TAVL *a){
    if(a){
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
}

static int maximo(int x, int y){
    if (x >= y){
        return x;
    }
    return y;
}

static int altura(TAVL *a){
    if (!a){
        return -1;
    }
    return a->alt;
}

static TAVL *RSD(TAVL *a){
    TAVL *aux = a->esq;
    a->esq = aux->dir;
    aux->dir = a;
    a->alt = maximo(altura(a->esq), altura(a->dir)) + 1;
    aux->alt = maximo(altura(aux->esq), altura(aux->dir)) + 1;
    return aux;
}

static TAVL *RSE(TAVL *a){
    TAVL *aux =  a->dir;
    a->dir = aux->esq;
    aux->esq = a;
    a->alt = maximo(altura(a->esq), altura(a->dir)) + 1;
    aux->alt = maximo(altura(aux->esq), altura(aux->dir)) + 1;
    return aux;
}

static TAVL *RED(TAVL *a){
    a->esq = RSE(a->esq);
    return RSD(a);
}

static TAVL *RDE(TAVL *a){
    a->dir = RSD(a->dir);
    return RSE(a);
}


TAVL *insere_avl(TAVL *a, int elem){
    if (!a){
        a = (TAVL*) malloc(sizeof(TAVL));
        a->info = elem;
        a->alt = 0;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (elem < a->info){
        a->esq = insere_avl(a->esq, elem);
        if ((altura(a->dir) - altura(a->esq)) == -2){ // Arvore desbalanceada na esquerda
            if ((altura(a->esq->dir) - altura(a->esq->esq) == -1)){  // Pai e filho possuem os mesmos sinais
                printf("Rotacao Simples Direita em (%d)\n", a->info);
                a = RSD(a);
            }
            else{  // Pai e filho possuem sinais diferentes 
                printf("Rotacao Esquerda Direita em (%d)\n", a->info);
                a = RED(a);
            }
        }
    }
    else if (elem > a->info){
        a->dir = insere_avl(a->dir, elem);
        if ((altura(a->dir) - altura(a->esq) == 2)){ // Arvore desbalanceada na direita
            if ((altura(a->dir->dir) - altura(a->dir->esq) == 1)){
                printf("Rotacao Simples Esquerda em (%d)\n", a->info);
                a = RSE(a);
            }
            else{
                printf("Rotacao Direita Esquerda em (%d)\n", a->info);
                a = RDE(a);
            }
        }
    }
    a->alt = maximo(altura(a->esq), altura(a->dir)) + 1;
    return a;
}


static int FB(TAVL *a){
    int alt_esq, alt_dir;
    if (!a){
        return -1;
    }
    if (!a->esq){
        alt_esq = -1;
    }
    else{
        alt_esq = a->esq->alt;
    }
    if (!a->dir){
        alt_dir = -1;
    }
    else{
        alt_dir = a->dir->alt;
    }
    return (alt_dir - alt_esq);  // dir - esq
}


TAVL *retira(TAVL *a, int elem){
    if (!a){
        return a;
    }
    else if (elem < a->info){ // Busca o elemento pela esquerda
        a->esq = retira(a->esq, elem);
        if (FB(a) == -2){
            if (FB(a->dir) <= 0){
                printf("Rotacao Simples Direita em (%d)\n", a->info);
                a = RSD(a);
            }
            else{
                printf("Rotacao Esquerda Direita em (%d)\n", a->info);
                a = RED(a);
            }
        }
    }
    else if (elem > a->info){ // Busca o elmento pela direita
        a->dir = retira(a->dir, elem);
        if (FB(a) == 2){
            if (FB(a->esq) >= 0){
                printf("Rotacao Simples Esquerda em (%d)\n", a->info);
                a = RSE(a);
            }
            else{
                printf("Rotacao Direita Esquerda em (%d)\n", a->info);
                a = RDE(a);
            }
        }
    }
    else{  // Encontrou o elemento
        if (a->esq){
            TAVL *aux = a->esq;
            while (aux->dir){
                aux = aux->dir;
            }
            a->info = aux->info; // a->info vai receber o maior elemento de seu filho na esquerda
            a->esq = retira(a->esq, aux->info);
            if (FB(a) == -2){
                if(FB(a->esq) <= 0){
                    printf("Rotacao Simples Direita em (%d)\n", a->info);
                    a = RSD(a);
                }
                else{
                    printf("Rotacao Direita Esquerda em (%d)\n", a->info);
                    a = RDE(a);
                }
            }
        }
        else{
            TAVL *aux = a;
            a = a->dir;
            free(aux);
            return a;
        }
    }
    a->alt = maximo(altura(a->esq), altura(a->dir)) + 1;
    return a;
}

TAVL *retira_pares(TAVL *a){
    if (!a){
        return NULL;
    }
    a->esq = retira_pares(a->esq);
    a->dir = retira_pares(a->dir);
    if (a->info % 2 == 0){
        a = retira(a, a->info);
    }
    return a;
}
