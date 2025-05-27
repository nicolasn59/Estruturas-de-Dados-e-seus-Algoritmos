#include "TLSE_Q11.h"

int main (void){
    TLSE *l1 = NULL, *l2 = NULL;
    l1 = insereFinal(l1, 12);
    l1 = insereFinal(l1, 5);
    l1 = insereFinal(l1, 56);
    l1 = insereFinal(l1, 90);
    l1 = insereFinal(l1, 1);
    l1 = insereFinal(l1, 0);
    l1 = insereFinal(l1, 78);
    l1 = insereFinal(l1, 35);
    l1 = insereFinal(l1, 12);

    imprimeLista(l1);
    l2 = ordena(l1);
    imprimeLista(l2);
    libera(l1);
    libera(l2);
    return 0;
}