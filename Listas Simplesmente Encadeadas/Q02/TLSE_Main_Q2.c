#include "TLSE_Q2.h"


int main(void){
    TLSE *l = NULL;
    int n = 1;
    for (int i=0; i<7; i++){
        l = insereFinal(l, n);
        n *= 2;
    }
    TLSE *l2 = inverte(l);
    imprimeLista(l);
    imprimeLista(l2);
    libera(l);
    libera(l2);
    return 0;
}
