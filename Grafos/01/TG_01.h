#include <stdio.h>
#include <stdlib.h>

typedef struct viz{
    int id_viz;
    struct viz *prox_viz; // Aponta para o próximo vizinho
} TVIZ;

typedef struct grafo{
    int id_vertice;  
    TVIZ *prim_viz; // Aponta para o primeiro vizinho do vértice
    struct grafo *prox_vert; // Aponta para o próximo vértice
} TG;

TG *inicializa();
TG *insere_vertice(TG *g, int v1);
TG *insere_aresta_orientado(TG *g, int v1, int v2);
void imprime(TG *g);
void libera(TG *g);
TG *retira_vertice(TG *g, int v);
