#include "TABB_04.h"

int main(void){
    TABB *a1 = NULL;
    int valores[] = {10, 9, 2, 3, 19, 12, 22, 1};
    for (int i=0; i < 8; i++){
        a1 = insere(a1, valores[i]);
    }
    printf("Arvore: ");
    imprime_pre(a1);
    printf("\n");

    int n;
    printf("Digite um valor para N: ");
    scanf("%d", &n);
    int len_vetor = qtd_elems_menores_N(a1, n);
    int *vetor = mN(a1, n);
    printf("Vetor: ");
    if (vetor != NULL){
        for (int i=0; i < len_vetor; i++){
            printf("%d ", vetor[i]);
        }
    }
    free(vetor);
    libera(a1);
    return 0;
}
