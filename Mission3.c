#include <stdio.h>
#include <limits.h>

#define V 13

int min(int a, int b) {
    return (a < b) ? a : b;
}

int bfs(int residualGraph[V][V], int source, int sink, int parent[]) {
    int visited[V] = {0};
    int queue[V];
    int front = 0, rear = 0;

    visited[source] = 1;
    queue[rear++] = source;
    parent[source] = -1;

    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < V; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                visited[v] = 1;
                queue[rear++] = v;
                parent[v] = u;

                if (v == sink)
                    return 1;
            }
        }
    }

    return 0;
}

int fordFulkerson(int graph[V][V], int source, int sink) {
    int residualGraph[V][V];
    int u, v;

    for (u = 0; u < V; u++) {
        for (v = 0; v < V; v++) {
            residualGraph[u][v] = graph[u][v];
        }
    }

    int parent[V];
    int maxFlow = 0;

    while (bfs(residualGraph, source, sink, parent)) {
        int pathFlow = INT_MAX;

        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

void maxCarCapacity() {
    int graph[V][V] = {{0, 30, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 16},
                      {0, 0, 0, 0, 0, 0, 0, 45, 50, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 7},
                      {70, 0, 0, 55, 15, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 30, 0, 60, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int source = 5;
    int sink = 11;
    int maxFlow = fordFulkerson(graph, source, sink);

    printf("Le nombre maximal de voitures pouvant circuler en même temps pendant une heure est : %d\n", maxFlow);

    int maxFlowBetween[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j) {
                maxFlowBetween[i][j] = fordFulkerson(graph, i, j);
            }
        }
    }

    printf("\nLe nombre maximal de voitures pouvant circuler entre chaque couple de villes :\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j) {
                printf("De la ville %c à la ville %c : %d\n", i + 'A', j + 'A', maxFlowBetween[i][j]);
            }
        }
    }
}

int main() {
    maxCarCapacity();

    return 0;
}
