#include "TG_06.h"

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
    gf1 = insere_aresta_nao_orientado(gf1, 2, 4);
    gf1 = insere_aresta_nao_orientado(gf1, 3, 4);


    imprime(gf1);
    printf("\n");
    int k;
    printf("Digite o valor de k: ");
    scanf("%d", &k);
    if (testek(gf1, k)){
        printf("Todos os vertices do grafo tem %d aresta(s).\n", k);
    }
    else{
        printf("Os vertices do grafo nao tem o grau igual a %d.\n", k);
    }
    libera(gf1);
}
