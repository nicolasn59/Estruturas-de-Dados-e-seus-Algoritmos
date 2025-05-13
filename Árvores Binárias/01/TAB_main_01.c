#include "TAB_Q01.h"

int main(void){
    TAB *a1 = inicializa_ab();
    TAB *a2 = inicializa_ab();

    // LADO ESQUERDO DA RAIZ
    TAB *folha1 = cria(2, NULL, NULL);
    TAB *folha2 = cria(6, NULL, NULL);
    TAB *folha3 = cria(7, folha2, folha1);

    // LADO DIREITO DA RAIZ
    TAB *folha4 = cria(0, NULL, NULL);
    TAB *folha5 = cria(1, NULL, NULL);
    TAB *folha6 = cria(3, NULL, folha4);
    TAB *folha7 = cria(7, folha6, folha5);

    // RAIZ PAI
    a1 = cria(8, folha3, folha7);
    a2 = copia(a1);
    printf("Arvore 1: ");
    imprime_pre(a1);
    printf("\n");
    printf("Arvore 2: ");
    imprime_pre(a2);
    libera(a1);
    libera(a2);
    return 0;
}