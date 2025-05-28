#include "TG_03.h"

int main(void){
    TG *gf1 = inicializa();
    gf1 = insere_vertice(gf1, 1);
    gf1 = insere_vertice(gf1, 2);
    gf1 = insere_vertice(gf1, 3);
    gf1 = insere_vertice(gf1, 4);

    gf1 = insere_aresta_nao_orientado(gf1, 1, 2);
    gf1 = insere_aresta_nao_orientado(gf1, 1, 3);
    gf1 = insere_aresta_nao_orientado(gf1, 1, 4);
    gf1 = insere_aresta_nao_orientado(gf1, 2, 3);
    gf1 = insere_aresta_nao_orientado(gf1, 3, 4);

    imprime(gf1);
    printf("\n");
    printf("Quantidade de nos: %d\n", nn(gf1));
    libera(gf1);
}
