#include "test.h"

graph* creer_graph() 
{
    graph* G = (graph*)malloc(sizeof(graph));
    G->nb_sommets = 0;
    G->nb_arcs = 0;
    G->matrice_adj = NULL;
    return G;
}

void lire_graph(graph* G) 
{

    int i, j;
    
    FILE* f = fopen("planete1.txt", "r");
    if (f == NULL) {
        printf("Erreur: impossible d'ouvrir le fichier \n");
        exit(1);
    }
    // Lecture du nombre de sommets
    fscanf(f, "%d", &(G->nb_sommets));
    G->nb_arcs = 0;

        // Allocation de la matrice d'adjacence
    G->matrice_adj = (int**)malloc(G->nb_sommets * sizeof(int*));
    for ( i = 0; i < G->nb_sommets; i++) {
        G->matrice_adj[i] = (int*)malloc(G->nb_sommets * sizeof(int));
        for ( j = 0; j < G->nb_sommets; j++) {
            G->matrice_adj[i][j] = 0;
        }
    }

    // Lecture des arcs
    while (fscanf(f, "%d %d", &i, &j) == 2) {
        G->matrice_adj[i-1][j-1] = 1;
        G->nb_arcs++;
    }

}

void afficher_Matrice(graph* G) {
    printf("Graphe de %d sommets et %d arcs:\n", G->nb_sommets, G->nb_arcs);
    for (int i = 0; i < G->nb_sommets; i++) {
        for (int j = 0; j < G->nb_sommets; j++) {
            printf("%d ", G->matrice_adj[i][j]);
        }
        printf("\n");
    }
}



