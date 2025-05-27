#include "TAVL_01.h"

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

// Para inserir um novo nó será necessário usar várias funções diferentes:

static int altura(TAVL *a){
    if (!a){  // Se for um nó vazio
        return -1;
    }
    return a->alt;
}

static int maximo(int x, int y){
    if (x >= y){
        return x;
    }
    return y;
}

// Funções de rotação para balancear a árvore:
static TAVL *RSD(TAVL *a){
    TAVL *u = a->esq;
    a->esq = u->dir;
    u->dir = a;
    a->alt = maximo(altura(a->esq), altura(a->dir)) + 1;
    u->alt = maximo(altura(u->esq), altura(u->dir)) + 1;
    return u;
}

static TAVL *RSE(TAVL *a){
    TAVL *u = a->dir;
    a->dir = u->esq;
    u->esq = a;
    a->alt = maximo(altura(a->esq), altura(a->dir)) + 1;
    u->alt = maximo(altura(u->esq), altura(u->dir)) + 1;
    return u;
}

static TAVL *RED(TAVL *a){
    a->esq = RSE(a->esq);
    return RSD(a);
}

static TAVL *RDE(TAVL *a){
    a->dir = RSD(a->dir);
    return RSE(a);
}
//.

TAVL *insere(TAVL *a, int elem){
    if (!a){
        // Não é preciso criar um novo ponteiro, pois aqui já temos acesso a estrutura da árvore
        a = (TAVL*) malloc(sizeof(TAVL));
        a->info = elem;
        a->alt = 0;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (elem < a->info){
        a->esq = insere(a->esq, elem);
        if ((altura(a->dir) - altura(a->esq)) == -2){  // a->dir - a->esq
            // o nó está desbalanceado para a esquerda
            if (altura(a->esq->dir) - altura(a->esq->esq) == -1){
                printf("Rotacao Simples Direita em (%d)\n", a->info);
                a = RSD(a);
            }
            else{
                printf("Rotacao Esquerda Direita em (%d)\n", a->info);
                a = RED(a);
            }
        }
    }
    else if (elem > a->info){
        a->dir = insere(a->dir, elem);
        if  ((altura(a->dir) - altura(a->esq)) == 2){  // a->dir - a->esq
            // o nó está desbalanceado para a direita
            if (altura(a->dir->dir) - altura(a->dir->esq) == 1){
                printf("Rotacao Simples Esquerda em (%d)\n", a->info);
                a = RSE(a);
            }
            else{
                printf("Rotacao Direita Esquerda em (%d)\n", a->info);
                a = RDE(a);
            }
        }
    }
    // Calcula a altura do nó atual
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
    return (alt_esq - alt_dir);  // esq - dir
}


TAVL *retira(TAVL *a, int elem){
    if (!a){
        return a;
    }
    else if (elem < a->info){ // Busca o elemento pela esquerda
        a->esq = retira(a->esq, elem);
        if (FB(a) == -2){
            if (FB(a->dir) <= 0){
                printf("Rotacao Simples Esquerda em (%d)\n", a->info);
                a = RSE(a);
            }
            else{
                printf("Rotacao Direita Esquerda em (%d)\n", a->info);
                a = RDE(a);
            }
        }
    }
    else if (elem > a->info){ // Busca o elmento pela direita
        a->dir = retira(a->dir, elem);
        if (FB(a) == 2){
            if (FB(a->esq) >= 0){
                printf("Rotacao Simples Direita em (%d)\n", a->info);
                a = RSD(a);
            }
            else{
                printf("Rotacao Esquerda Direita em (%d)\n", a->info);
                a = RED(a);
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
                    printf("Rotacao Simples Esquerda em (%d)\n", a->info);
                    a = RSE(a);
                }
                else{
                    printf("Rotacao Esquerda Direita em (%d)\n", a->info);
                    a = RED(a);
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
