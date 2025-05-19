#include "TAB_13.h"

int main(void){
    TAB *a1 = NULL; // Inicializando a árvore
    // Lado esquerdo da raiz
    TAB *no1 = cria(2, NULL, NULL);
    TAB *no2 = cria(3, NULL, NULL);
    TAB *no3 = cria(10, no1, no2);
    
    // Lado direito da raiz
    TAB *no4 = cria(1, NULL, NULL);
    TAB *no5 = cria(7, no4, NULL);

    // Raiz pai
    a1 = cria(8, no3, no5);
    printf("Arvore: ");
    imprime_sim(a1);
    printf("\nDigite o numero que voce quer procurar na arvore: ");
    int elemento;
    scanf("%d", &elemento);
    if (busca(a1 , elemento)){
        printf("\nO elemento %d esta na arvore!\n", elemento);
    } else {
        printf("O elemento %d nao esta na arvore!\n", elemento);
    }
    libera(a1);
    return 0;
}
