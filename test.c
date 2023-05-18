#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 100

// Structure de données pour stocker une arête de graphe
struct Edge {
    int source, dest, weight;
};

// Structure de données pour représenter un graphe
struct Graph {
    struct Edge edges[MAX_NODES];
    int numEdges;
    int numNodes;
};

// Fonction pour initialiser un graphe vide
void initializeGraph(struct Graph* graph, int numNodes) {
    graph->numEdges = 0;
    graph->numNodes = numNodes;
}

// Fonction pour ajouter une arête au graphe
void addEdge(struct Graph* graph, int source, int dest, int weight) {
    graph->edges[graph->numEdges].source = source;
    graph->edges[graph->numEdges].dest = dest;
    graph->edges[graph->numEdges].weight = weight;
    graph->numEdges++;
}

// Fonction pour trouver le sommet avec la distance minimale non traitée
int findMinDistanceVertex(int distances[], bool visited[], int numNodes) {
    int minDistance = INT_MAX;
    int minVertex;

    for (int v = 0; v < numNodes; v++) {
        if (visited[v] == false && distances[v] < minDistance) {
            minDistance = distances[v];
            minVertex = v;
        }
    }

    return minVertex;
}

// Fonction pour afficher le chemin le plus court à partir de la source jusqu'au sommet donné
void printPath(int parent[], int vertex, int source) {
    if (vertex == source) {
        printf("%d", vertex);
    } else if (parent[vertex] == -1) {
        printf("Pas de chemin de %d à %d", source, vertex);
    } else {
        printPath(parent, parent[vertex], source);
        printf(" -> %d", vertex);
    }
}

// Fonction pour exécuter l'algorithme de Dijkstra
void dijkstra(struct Graph* graph, int source) {
    int numNodes = graph->numNodes;
    int distances[MAX_NODES];
    bool visited[MAX_NODES];
    int parent[MAX_NODES];

    // Initialisation des distances à l'infini et des sommets non visités
    for (int v = 0; v < numNodes; v++) {
        distances[v] = INT_MAX;
        visited[v] = false;
        parent[v] = -1;
    }

    // Distance de la source à elle-même est de zéro
    distances[source] = 0;

    // Trouve le chemin le plus court pour tous les sommets
    for (int i = 0; i < numNodes - 1; i++) {
        int u = findMinDistanceVertex(distances, visited, numNodes);
        visited[u] = true;

        // Met à jour les distances des sommets adjacents non visités
        for (int j = 0; j < graph->numEdges; j++) {
            int v = graph->edges[j].dest;
            int weight = graph->edges[j].weight;

            if (visited[v] == false && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                parent[v] = u;
            }
        }
    }

    // Affiche les chemins les plus courts et leurs distances
    for (int v = 0; v < numNodes; v++) {
        if (v != source) {
            printf("Chemin le plus court de %d à %d : ", source, v);
            printPath(parent, v, source);
            printf(", Distance : %d\n", distances[v]);
        }
    }
}

int main() {
    struct Graph graph;
    int numNodes = 5;

    initializeGraph(&graph, numNodes);

    // Ajoute les arêtes au graphe
    addEdge(&graph, 0, 1, 10);
    addEdge(&graph, 0, 4, 3);
    addEdge(&graph, 1, 2, 2);
    addEdge(&graph, 1, 4, 4);
    addEdge(&graph, 2, 3, 9);
    addEdge(&graph, 3, 2, 7);
    addEdge(&graph, 4, 1, 1);
    addEdge(&graph, 4, 2, 8);
    addEdge(&graph, 4, 3, 2);

    int source = 0; // Sommet source

    dijkstra(&graph, source);

    return 0;
}
