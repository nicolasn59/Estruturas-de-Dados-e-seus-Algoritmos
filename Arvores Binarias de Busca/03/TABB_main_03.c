#include "TABB_03.h"

int main(void){
    TABB *a1 = NULL;
    int valores[] = {10, 9, 2, 3, 19, 12, 22};
    for (int i=0; i < 7; i++){
        a1 = insere(a1, valores[i]);
    }
    imprime_pre(a1);
    printf("\n");
    a1 = retira_impares(a1);
    imprime_pre(a1);
    libera(a1);
    return 0;
}
