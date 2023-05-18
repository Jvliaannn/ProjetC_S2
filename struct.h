#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <stdbool.h>

typedef struct Node {             // Noeud d'un graphe
                            
    int vertex;
    struct Node* next;

} Node;

typedef struct Graphe {

    int numVertices;
    Node** adjacencyList;

} Graph;

// Initialisation du graphe avec un certain nombre de sommets
Graph* createGraph(int numVertices) {

    Graphe* graphe = (Graph*)malloc(sizeof(Graph));
    graphe -> numVertices = numVertices;
    graphe -> adjacencyList = (Node**)malloc(numVertices * sizeof(Node*));

    for (int i = 0; i < numVertices; i++) {

        graphe -> adjacencyList[i] = NULL;
    }

    return graphe;
}
