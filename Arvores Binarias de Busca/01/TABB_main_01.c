#include "TABB_01.h"

int main(void){
    TABB *a1 = inicializa();
    int num;
    printf("Digite um valor para inserir na arvore (para encerrar digite um valor menor que 0): ");
    scanf("%d", &num);
    while (num >= 0){
        a1 = insere(a1, num);
        printf("Digite um valor para inserir na arvore (para encerrar digite um valor menor que 0): ");
        scanf("%d", &num);
    }
    imprime_pre(a1);
    printf("\n");
    TABB *maior_elemento = maior(a1);
    if (maior_elemento){
        printf("O maior elemento da arvore eh %d\n", maior_elemento->info);
    }
    else{
        printf("Arvore nao existe!\n");
    }
    libera(a1);
    return 0;
}
