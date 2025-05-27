#include "TLSE_Q1.h"

int main(){
    TLSE *l = NULL;
    int n = 1;
    for (int i=0; i<7; i++){
        l = insereFinal(l, n);
        n *= 2;
    }
    imprimeLista(l);
    inverte(&l);
    imprimeLista(l);
    libera(l);
    return 0;
}
