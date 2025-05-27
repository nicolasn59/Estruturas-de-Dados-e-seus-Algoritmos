#include "TABB_02.h"

int main(void){
    TABB *a1 = NULL;
    int valores[] = {12, 81, 9, 11, 12, 5, 32, 7, 8, 2, 0, -1, 1, 24};
    for (int i=0; i < 14; i++){
        a1 = insere(a1, valores[i]);
    }
    imprime_pre(a1);
    printf("\n");
    TABB *menor_elemento = menor(a1);
    printf("Menor: %d\n", menor_elemento->info);
    libera(a1);
    return 0;
}
