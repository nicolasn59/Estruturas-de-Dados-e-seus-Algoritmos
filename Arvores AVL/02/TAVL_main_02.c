#include "TAVL_02.h"

int main(void){
    TAVL *a1 = NULL;
    // Construindo árvore dada no enunciado
    int avl_elems[] = {61, 78, 34, 64, 47, 87, 19, 15, 29, 42, 53, 76, 84, 13, 17, 32};
    for (int i=0; i < 16; i++){
        a1 = insere_avl(a1, avl_elems[i]);
    }

    printf("Inserindo elementos: \n");
    // Elementos que serão inseridos na árvore AVL
    int elems_inserir[] = {1, 65, 12, 18, 66, 38, 95, 58, 59, 70, 68, 39, 62, 60,43, 16, 67, 36, 35};
    for (int i=0; i < 19; i++){
        printf("%d foi inserido!\n", elems_inserir[i]);
        a1 = insere_avl(a1, elems_inserir[i]);
    }

    printf("\nRemovendo elementos: \n");
    // Elementos que serão removidos
    int elems_remover[] = {35, 34, 67, 16, 42, 60, 62, 39, 68, 70, 59, 58, 95, 38, 66, 18, 12, 64, 1};
    for (int i=0; i < 19; i++){
        printf("%d foi removido!\n", elems_remover[i]);
        a1 = retira(a1, elems_remover[i]);
    }
    
    printf("\nSimetrica com pares: ");
    imprime_sim(a1);

    a1 = retira_pares(a1); // UM BÔNUS
    printf("\nSimetrica sem pares: ");
    imprime_sim(a1);
    libera(a1);
    return 0;
}