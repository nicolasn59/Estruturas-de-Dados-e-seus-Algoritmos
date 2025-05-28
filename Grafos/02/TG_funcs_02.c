#include "TG_02.h"

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

TG *retira_vertice(TG *g, int v){
    TG *p = busca_vertice(g, v); // Verificando se o vértice existe no grafo
    if (p){
        TVIZ *viz = p->prim_viz;
        while (viz){  
            // Limpando todas arestas do vértice v
            TVIZ *temp_viz = viz;
            viz = viz->prox_viz;
            free(temp_viz);
        }
        p->prim_viz = NULL; // Primeiro vizinho será NULL
        TG *atual = g; // Auxiliar para percorrer os vértices
        
        while (atual){ 
            TVIZ *viz_ant = NULL; // vizinho anterior
            TVIZ *viz_at = atual->prim_viz; // vizinho atual
            while ((viz_at) && (viz_at->id_viz != v)){
                viz_ant = viz_at;
                viz_at = viz_at->prox_viz;
            }
            if (viz_at){
                 if (!viz_ant){ // v era o primeiro nó da lista (primeira aresta)
                    atual->prim_viz = viz_at->prox_viz;
                }
                else{
                    viz_ant->prox_viz = viz_at->prox_viz; // vizinho atual é ignorado
                }
                free(viz_at); // libera vizinho atual se for igual a v
            }
            atual = atual->prox_vert;  // Passa para o próximo vértice do grafo
        }
        TG *p_ant = NULL; // Anterior do vértice que queremos remover
        if (g == p){ // v é o primeiro vértice
            g = g->prox_vert;
            free(p);
        }
        else{ 
            TG *p_ant = g; // vértice anterior
            while (p_ant->prox_vert != p){ // Até encontrar o vértice p (v)
                p_ant = p_ant->prox_vert;
            }
            p_ant->prox_vert = p->prox_vert;
            free(p);
        }
    }
    return g;
}
