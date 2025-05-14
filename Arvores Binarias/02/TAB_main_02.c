#include "TAB_02.h"

int main(void){
    TAB *a1 = NULL;  // Inicializa árvore binária
    TAB *a2 = NULL;

    // LADO ESQUERDO DA RAIZ
    TAB *folha1 = cria(3, NULL, NULL);
    TAB *folha2 = cria(1, NULL, NULL);
    TAB *folha3 = cria(2, folha1, folha2);

    // LADO DIREITO DA RAIZ
    TAB *folha4 = cria(5, NULL, NULL);
    TAB *folha5 = cria(7, NULL, NULL);
    TAB *folha6 = cria(3, folha4, folha5);

    // RAIZ
    a1 = cria(8, folha3, folha6);
    a2 = espelho(a1);
    
    printf("Arvore 1: ");
    imprime_sim(a1);
    printf("\n");
    printf("Arvore 2: ");
    imprime_sim(a2);
    printf("\n");
    libera(a1);
    libera(a2);
    return 0;
}