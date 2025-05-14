#include "TAB_05.h"

int main(void){
    TAB *a = NULL; // Inicializando a árvore
    // Lado esquerdo da raiz
    TAB *no1 = cria(2, NULL, NULL);
    TAB *no2 = cria(3, NULL, NULL);
    TAB *no3 = cria(10, NULL, no2);
    
    // Lado direito da raiz
    TAB *no4 = cria(1, NULL, NULL);
    TAB *no5 = cria(7, no4, NULL);

    // Raiz pai
    a = cria(9, no3, no5);
    printf("Arvore: ");
    imprime_sim(a);
    printf("\n");
    int altura_arvore = altura(a);
    printf("%d\n", altura_arvore);
    libera(a);
    return 0;
}