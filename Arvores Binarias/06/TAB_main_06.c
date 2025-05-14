#include "TAB_06.h"

int main(void){
    // Inicializando árvores
    TAB *a1 = NULL;
    TAB *a2 = NULL;

    // Lado esquerdo da raiz
    TAB *no1 = cria(2, NULL, NULL);
    TAB *no2 = cria(99, NULL, NULL);
    TAB *no3 = cria(20, no1, no2);

    // Lado direito da raiz
    TAB *no4 = cria(12, NULL, NULL);
    TAB *no5 = cria (0, NULL, no4);

    // RAIZ PAI
    a1 = cria(10, no3, no5);
   a2 = cria(10, NULL, no5);

    printf("Arvore 1: ");
    imprime_pos(a1);
    printf("\n");
    printf("Arvore 2: ");
    imprime_pos(a2);
    printf("\n");

    if (igual(a1, a2)){
        printf("As duas arvores sao iguais.\n");
    }
    else{
        printf("As duas arvores sao diferentes.\n");
    }

    libera(a1);
    libera(a2);
    return 0;
}
