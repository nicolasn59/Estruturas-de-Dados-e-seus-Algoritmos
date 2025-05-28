#include "TG_07.h"

TG *inicializa(){
    return NULL;
}

void imprime(TG *g){
    while (g){
        printf("Vertice: %d\n", g->id_vertice);
        printf("Vizinhos: ");
        TVIZ *v = g->prim_viz;
        while (v){
            printf("%d ", v->id_viz);
            v = v->prox_viz;            
        }
        printf("\n");
        g = g->prox_vert;
    }
}

void libera(TG *g){
    while (g){
        TVIZ *v = g->prim_viz;
        while (v){
            TVIZ *temp_viz = v;
            v = v->prox_viz;
            free(temp_viz);
        }
        TG *temp_vert = g;
        g = g->prox_vert;
        free(temp_vert);
    }
}

static TG *busca_vertice(TG *g, int v1){
    while ((g) && (g->id_vertice != v1)){
        g = g->prox_vert;
    }
    return g;
}

static TVIZ *busca_aresta(TG *g, int v1, int v2){
    TG *p1 = busca_vertice(g, v1);
    TG *p2 = busca_vertice(g, v2);
    TVIZ *aresta = NULL;
    if ((p1) && (p2)){
        aresta = p1->prim_viz;
        while ((aresta) && (aresta->id_viz != v2)){
            aresta = aresta->prox_viz;
        }
    }
    return aresta;
}

TG *insere_vertice(TG *g, int v1){
    TG *p = busca_vertice(g, v1); 
    if (!p){  // Verifica se o vértice já existe no grafo
        p = (TG*) malloc(sizeof(TG));
        p->id_vertice = v1;
        p->prox_vert = g;
        p->prim_viz = NULL;
        g = p;
    }
    return g;
}

static void insere_um_sentido(TG *g, int v1, int v2){
    TG *p = busca_vertice(g, v1);
    if (p){
        TVIZ *nova = (TVIZ *) malloc(sizeof(TVIZ));
        nova->id_viz = v2;
        nova->prox_viz = p->prim_viz;
        p->prim_viz = nova;
    }
}

TG *insere_aresta_nao_orientado(TG *g, int v1, int v2){
    TVIZ *v = busca_aresta(g, v1, v2);
    if (!v){
        // Insere v1 em v2 e v2 em v1
        insere_um_sentido(g, v1, v2);
        insere_um_sentido(g, v2, v1);
    }
    return g;
}

TG * insere_aresta_orientado(TG *g, int v1, int v2){
    TVIZ *v = busca_aresta(g, v1, v2);
    if (!v){
        insere_um_sentido(g, v1, v2);
    }
    return g;
}

int ig (TG *g1, TG *g2){
    while(g1 && g2){  // Enquanto g1 ou g2 existirem
        if (g1->id_vertice != g2->id_vertice){
            return 0;
        }
        TVIZ *viz1 = g1->prim_viz;
        TVIZ *viz2 = g2->prim_viz;
        while (viz1 && viz2){ // Enquanto viz1 ou viz2 existirem
            if (viz1->id_viz != viz2->id_viz){
                return 0;
            }
            viz1 = viz1->prox_viz;
            viz2 = viz2->prox_viz;
        }
        if (viz1 || viz2){  // Entra aqui se viz1 ou viz2 for NULL, apenas 1
            return 0;
        }
        g1 = g1->prox_vert;
        g2 = g2->prox_vert;
    }
    if (g1 || g2){ // Entra aqui se g1 ou g2 for NULL, apenas 1 deles
        return 0;
    }
    return 1;
}
