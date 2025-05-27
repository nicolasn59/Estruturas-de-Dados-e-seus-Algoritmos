#include "TLSE_Q12.h"

int main(void){
    TLSE *l1 = NULL;
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
    ordena(l1);
    imprimeLista(l1);
    libera(l1);
    return 0;
}
