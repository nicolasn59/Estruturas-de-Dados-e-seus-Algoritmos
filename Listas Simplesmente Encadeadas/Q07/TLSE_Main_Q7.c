#include "TLSE_Q7.h"

int main(void){
    TLSE *l1 = NULL;
    int num = 2;
    for (int i=0; i<10; i++){
        l1 = insereFinal(l1, num);
        num += 3;
    }
    
    printf("Lista 1 - Antes: ");
    imprimeLista(l1);
    printf("\n");

    i_p(&l1);  // Passagem por referência para alterar a lista na main

    printf("Lista 1 - Depois: ");
    imprimeLista(l1);
    printf("\n");
    libera(l1);
    return 0;
}

