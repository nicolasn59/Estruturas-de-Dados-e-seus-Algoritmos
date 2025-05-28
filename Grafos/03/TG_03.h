#include <stdio.h>
#include <stdlib.h>

typedef struct viz{
    int id_viz;
    struct viz *prox_viz;
} TVIZ;

typedef struct grafo{
    int id_vertice;
    TVIZ *prim_viz;
    struct grafo *prox_vert;
} TG;

TG *inicializa();
TG *insere_vertice(TG *g, int v1);
TG *insere_aresta_orientado(TG *g, int v1, int v2);
TG *insere_aresta_nao_orientado(TG *g, int v1, int v2);
void imprime(TG *g);
void libera(TG *g);
int nn(TG *g);
