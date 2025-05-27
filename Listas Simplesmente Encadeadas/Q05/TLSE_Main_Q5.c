#include "TLSE_Q5.h"

int main(void){
    TLSE *l1 = NULL;
    int num = 2, cont=0;
    for (int i=0; i<10; i++){
        l1 = insereInicio(l1, num);
        num *= 10;
        cont++;
        if (cont == 3){
            num = 2;
            cont = 0;
        }
    }
    imprimeLista(l1);
    printf("Digite um numero para ser removido da lista: ");
    scanf("%d", &num);
    printf("%d\n", num);
    l1 = rto(l1, num);
    imprimeLista(l1);
    libera(l1);
    return 0;
}
