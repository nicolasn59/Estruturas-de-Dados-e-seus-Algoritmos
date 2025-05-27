#include "TLSE_Q10.h"

int main(void){
    TLSE *l1 = NULL, *l2 = NULL;
    int n1 = 4, n2 = 5;
    for (int i=0; i<6; i++){
        l1 = insereFinal(l1, n1);
        l2 = insereFinal(l2, n2);
        n1 *= 4;
        n2 *= 4;
    }
    imprimeLista(l1);
    imprimeLista(l2);
    if (Contrario(l1, l2)){
        printf("SAO INVERSAS!\n");
    }
    else{
        printf("NAO SAO INVERSAS!\n");
    }
    return 0;
}