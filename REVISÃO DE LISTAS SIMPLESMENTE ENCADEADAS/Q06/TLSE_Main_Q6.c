#include "TLSE_Q6.h"

int main(void){
    TLSE *l1 = NULL;
    int num = 2;
    for (int i=0; i<10; i++){
        l1 = insereInicio(l1, num);
        num += 3;
    }

    printf("Lista 1: ");
    imprimeLista(l1);
    printf("\n");

    TLSE * l2 = NULL;
    l2 = i_p(l1);

    printf("Lista 2: ");
    imprimeLista(l2);
    printf("\n");
    return 0;
}
