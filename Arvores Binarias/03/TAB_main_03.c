#include "TAB_03.h"

int main(void){
    TAB *a = NULL; // Inicializando a árvore
    
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
    imprime_pos(a);
    printf("\n");
    TAB *no_max = maior(a);
    printf("Maior No: %d\n", no_max->info);
    libera(a);
    return 0;
}
