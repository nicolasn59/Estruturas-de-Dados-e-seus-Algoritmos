#include "TG_04.h"

int main(void){

    // Grafo não orientado
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
    printf("Quantidade de arestas no grafo nao orientado: %d\n\n", na_nao_orientado(gf1));
    libera(gf1);


    // Grafo Orientado
    gf1 = inicializa();
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
    printf("Quantidade de arestas no grafo orientado: %d\n", na_orientado(gf1));
    libera(gf1);
}
