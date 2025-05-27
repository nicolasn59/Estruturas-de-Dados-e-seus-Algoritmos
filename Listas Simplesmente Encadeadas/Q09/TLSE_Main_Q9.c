#include "TLSE_Q9.h"

int main(void){
    TLSE *l1 = NULL, *l2 = NULL;
    int n1 = 2, n2 = 5;
    for (int i=0; i<5; i++){
        l1 = insereFinal(l1, n1);
        l2 = insereFinal(l2, n2);
        n1 *= 4;
        n2 *= 4;
    }
    imprimeLista(l1);
    imprimeLista(l2);

    l1 = junta_listas(l1, l2);
    imprimeLista(l1);
    libera(l1);
    libera(l2);
    return 0;
}
