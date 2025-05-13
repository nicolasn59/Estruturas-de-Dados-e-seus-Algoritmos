#include "TAB_04.h"

int main(void){
    // Inicializando árvore
    TAB *a = NULL;

    // Lado esquerdo da raiz
    TAB *no1 = cria(3, NULL, NULL);
    TAB *no2 = cria(13, NULL, NULL);
    TAB *no3 = cria(1, no1, no2);

    // Lado direito da raiz
    TAB *no4 = cria(5, NULL, NULL);
    TAB *no5 = cria(20, NULL, NULL);
    TAB *no6 = cria(35, no5, no4);

    // Raiz
    a = cria(7, no3, no6);
    
    printf("Arvore: ");
    imprime_pre(a);
    printf("\n");
    TAB *no_min = menor(a);
    printf("Menor No: %d\n", no_min->info);
    libera(a);
    
}