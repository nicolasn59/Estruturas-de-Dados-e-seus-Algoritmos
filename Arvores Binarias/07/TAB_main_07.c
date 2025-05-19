#include "TAB_07.h"

int main(void){
    TAB *a1 = NULL; // Inicializando a árvore
    // Lado esquerdo da raiz
    TAB *no1 = cria(2, NULL, NULL);
    TAB *no2 = cria(3, NULL, NULL);
    TAB *no3 = cria(10, no1, no2);
    
    // Lado direito da raiz
    TAB *no4 = cria(1, NULL, NULL);
    TAB *no5 = cria(7, no4, NULL);

    // Raiz pai
    a1 = cria(8, no3, no5);
    printf("Arvore: ");
    imprime_sim(a1);
    printf("\n");
    TAB *a2 = retira_pares(a1);
    printf("Arvore sem pares: ");
    imprime_sim(a2);
    printf("\n");
    libera(a1);
    libera(a2);
    return 0;
}