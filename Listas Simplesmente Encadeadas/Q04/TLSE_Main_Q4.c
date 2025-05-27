#include "TLSE_Q4.h"

int main(void){
    TLSE *l1 = NULL;
    int num = 4;
    for (int i=0; i<5; i++){
        l1 = insereInicio(l1, num);
        num *= 3;
    }
    TLSE *l2 = copia(l1);
    imprimeLista(l1);
    imprimeLista(l2);
    libera(l1);
    libera(l2);
    return 0;
}
