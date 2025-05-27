#include "TLSE_Q3.h"

int main(void){
    TLSE *l1 = NULL;
    int valor = 5;
    for (int i=0; i<5; i++){
        l1 = insereFinal(l1, valor);
        valor += 5;
    }
    imprimeLista(l1);
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    l1 = desloca(l1, num);
    imprimeLista(l1);
    libera(l1);
    return 0;
}
