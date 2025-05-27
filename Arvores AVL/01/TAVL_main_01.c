#include "TAVL_01.h"

int main(void){
    TAVL *a1 = NULL;
    a1 = insere(a1, 50);  // 50 é primeiro elemento (regra do enunciado)
    int elems_inserir[] = {1, 64, 12, 18, 66, 38, 95, 58, 59, 70, 68, 39, 62, 7, 60, 43, 16, 67, 34, 35};
    printf("Insercao de nos: \n");
    for (int i=0; i < 20; i++){
        printf("%d foi inserido!\n", elems_inserir[i]);
        a1 = insere(a1, elems_inserir[i]);
    }
    imprime_sim(a1);
    printf("\n\n");
    printf("Remocao de nos:\n");
    int elems_retirar[] = {50, 95, 70, 60, 35};
    for (int i=0; i < 5; i++){
        printf("%d foi removido!\n", elems_retirar[i]);
        a1 = retira(a1, elems_retirar[i]);
    }
    imprime_sim(a1);
    printf("\n");
    libera(a1);
    return 0;
}
