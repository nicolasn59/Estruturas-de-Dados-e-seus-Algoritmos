#include "TG_07.h"

int main(void){

    // Grafo orientado
    printf("Grafo Orientado: \n");
    TG *gf1 = inicializa();
    gf1 = insere_vertice(gf1, 1);
    gf1 = insere_vertice(gf1, 2);
    gf1 = insere_vertice(gf1, 3);
    gf1 = insere_vertice(gf1, 4);

    gf1 = insere_aresta_orientado(gf1, 1, 2);
    gf1 = insere_aresta_orientado(gf1, 1, 3);
    gf1 = insere_aresta_orientado(gf1, 1, 4);
    gf1 = insere_aresta_orientado(gf1, 2, 4);
    gf1 = insere_aresta_orientado(gf1, 3, 1);
    gf1 = insere_aresta_orientado(gf1, 2, 1);
    gf1 = insere_aresta_orientado(gf1, 4, 4);

    imprime(gf1);
    printf("\n");

    // Grafo não orientado
    printf("Grafo Nao Orientado: \n");
    TG *gf2 = inicializa();
    gf2 = insere_vertice(gf2, 1);
    gf2 = insere_vertice(gf2, 2);
    gf2 = insere_vertice(gf2, 3);
    gf2 = insere_vertice(gf2, 4);

    gf2 = insere_aresta_nao_orientado(gf2, 1, 2);
    gf2 = insere_aresta_nao_orientado(gf2, 1, 3);
    gf2 = insere_aresta_nao_orientado(gf2, 1, 4);
    gf2 = insere_aresta_nao_orientado(gf2, 2, 3);
    gf2 = insere_aresta_nao_orientado(gf2, 2, 4);
    gf2 = insere_aresta_nao_orientado(gf2, 3, 4);

    imprime(gf2);
    printf("\n");
    
    if (ig(gf1, gf2)){
        printf("Os dois grafos sao iguais!\n");
    }
    else{
        printf("Os dois grafos sao diferentes!\n");
    }

    libera(gf1);
    libera(gf2);
}
