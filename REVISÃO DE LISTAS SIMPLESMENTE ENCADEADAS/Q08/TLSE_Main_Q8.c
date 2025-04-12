#include "TLSE_Q8.h"

int main(void){
    TLSE *l1 = NULL, *l2 = NULL;

    printf("\nTESTE 1:\n\n");
    imprimeLista(l1);
    imprimeLista(l2);
    if (igual(l1, l2)){
        printf("\nAs duas listas sao iguais!\n\n");
    }
    else{
        printf("\nAs duas listas sao diferentes!\n\n");
    }

    printf("TESTE 2:\n\n");
    int num1 = 2, num2 = 3;
    for (int i=0; i<5; i++){
        l1 = insereFinal(l1, num1);
        l2 = insereFinal(l2, num2);
        num1 *= 2;
        num2 *= 3;
    }
    imprimeLista(l1);
    imprimeLista(l2);
    if (igual(l1, l2)){
        printf("\nAs duas listas sao iguais!\n\n");
    }
    else{
        printf("\nAs duas listas sao diferentes!\n\n");
    }

    l1 = apagarLista(l1);
    l2 = apagarLista(l2);
    
    printf("TESTE 3:\n\n");
    num1 = 10;
    num2 = 10;
    for (int i=0; i<5; i++){
        l1 = insereFinal(l1, num1);
        l2 = insereFinal(l2, num2);
        num1 *= 2;
        num2 *= 2;
    }
    imprimeLista(l1);
    imprimeLista(l2);
    if (igual(l1, l2)){
        printf("\nAs duas listas sao iguais!\n\n");
    }
    else{
        printf("\nAs duas listas sao diferentes!\n\n");
    }

    return 0;
}
