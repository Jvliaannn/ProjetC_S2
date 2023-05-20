#include "struct.h"

void initializeGraph(Graph* graph) {
    graph->Nbsommet = 0;
    graph->sommetDeDepart = 0;
    graph->sommetArrive = 0;
    graph->MatriceAdjacente = NULL;
    graph->listeSuccesseurs = NULL;
}

void addEdge(Graph* graph, int sommet, int successeurs) 
{
    if (sommet >= 0 && sommet < graph->Nbsommet && successeurs >= 0 && successeurs < graph->Nbsommet) {
        graph->MatriceAdjacente[sommet][successeurs] = 1;
    }
}

void LireGraphe(Graph* graph, FILE* fichier) 
{
    int sommetDeDepart, sommetArrive;
    int maxSommet = 0; // Variable pour stocker la valeur du sommet la plus grande

    initializeGraph(graph);

    fscanf(fichier, "Debut: %d\n", &(graph->sommetDeDepart));
    fscanf(fichier, "Fin: %d\n", &(graph->sommetArrive));

    // Chercher la valeur maximale du sommet dans le fichier
    int sommet, successeurs;
    char fleche[3];

    while (fscanf(fichier, "%d %3s %d", &sommet, fleche, &successeurs) == 3) {
        if (sommet > maxSommet) {
            maxSommet = sommet;
        }
        if (successeurs > maxSommet) {
            maxSommet = successeurs;
        }
    }

    graph->Nbsommet = maxSommet + 1; // Le nombre de sommets est la valeur maximale + 1

    // Allocation dynamique de la matrice d'adjacence
    graph->MatriceAdjacente = (int**)malloc(graph->Nbsommet * sizeof(int*));
    for (int i = 0; i < graph->Nbsommet; i++) {
        graph->MatriceAdjacente[i] = (int*)calloc(graph->Nbsommet, sizeof(int));
    }

    // Réinitialiser le curseur de lecture du fichier
    fseek(fichier, 0, SEEK_SET);

    // Lire à nouveau le fichier pour remplir la matrice d'adjacence
    fscanf(fichier, "Debut: %d\n", &(graph->sommetDeDepart));
    fscanf(fichier, "Fin: %d\n", &(graph->sommetArrive));

    while (fscanf(fichier, "%d %3s %d", &sommet, fleche, &successeurs) == 3) {
        if (strcmp(fleche, "->") == 0) {
            addEdge(graph, sommet, successeurs);
        } else if (strcmp(fleche, "<-") == 0) {
            addEdge(graph, successeurs, sommet);
        }
    }
}

// Afficher la matrice d'adjacence du graphe
void printAdjacencyMatrix(Graph* graph) {
    int i, j;
    for (i = 0; i < graph->Nbsommet; i++) {
        for (j = 0; j < graph->Nbsommet; j++) {
            printf("%d ", graph->MatriceAdjacente[i][j]);
        }
        printf("\n");
    }
}
// Transformer la matrice d'adjacence en liste de successeurs
void convertirMatriceEnListeSuccesseurs(Graph* graph) {
    graph->listeSuccesseurs = (Noeud**)malloc(graph->Nbsommet * sizeof(Noeud*));

    for (int i = 0; i < graph->Nbsommet; i++) {
        graph->listeSuccesseurs[i] = NULL;
        for (int j = 0; j < graph->Nbsommet; j++) {
            if (graph->MatriceAdjacente[i][j] == 1) {
                Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
                nouveauNoeud->sommet = j;
                nouveauNoeud->suivant = graph->listeSuccesseurs[i];
                graph->listeSuccesseurs[i] = nouveauNoeud;
            }
        }
    }
}

// Afficher la liste de successeurs du graphe
void printSuccessorList(Graph* graph) {
    for (int i = 0; i < graph->Nbsommet; i++) {
        printf("Successeurs de %d : ", i);
        Noeud* noeud = graph->listeSuccesseurs[i];
        while (noeud != NULL) {
            printf("%d ", noeud->sommet);
            noeud = noeud->suivant;
        }
        printf("\n");
    }
}

void parcoursProfondeur(Graph* graph, int sommet, bool* visite) 
{
    visite[sommet] = true;
    printf("%d ", sommet);

    Noeud* successeurs = graph->listeSuccesseurs[sommet];
    while (successeurs != NULL) {
        int successeur = successeurs->sommet;
        if (!visite[successeur]) {
            parcoursProfondeur(graph, successeur, visite);
        }
        successeurs = successeurs->suivant;
    }
    
}

void rechercheEnProfondeur(Graph* graph) 
{
    bool* visite = (bool*)calloc(graph->Nbsommet, sizeof(bool));
    printf("Ordre suffixe du parcours en profondeur : ");
    parcoursProfondeur(graph, graph->sommetDeDepart, visite);
    printf("\n");
    free(visite);
}

/*bool parcoursProfondeur(Graph* graph, int sommet, bool* visite, int sommetArrive) 
{
    visite[sommet] = true;

    printf("%d ", sommet);

    if (sommet == sommetArrive) {
        return true;
    }

    Noeud* successeurs = graph->listeSuccesseurs[sommet];
    while (successeurs != NULL) {
        int successeur = successeurs->sommet;
        if (!visite[successeur]) {
            if (parcoursProfondeur(graph, successeur, visite, sommetArrive)) {
                return true;
            }
        }
        successeurs = successeurs->suivant;
    }

    return false;
}*/








/*// Fonction auxiliaire pour explorer un sommet
void explorer(Graph* graph, int sommet, bool visited[]) {
    visited[sommet] = true;
    printf("%d ", sommet);

    for (int t = 0; t < graph->Nbsommet; t++) {
        if (graph->MatriceAdjacente[sommet][t] && !visited[t]) {
            explorer(graph, t, visited);
        }
    }
}

//Parcours en profondeur du graphe
void parcoursProfondeur(Graph* graph) {
    bool visited[MAX_VERTICES] = { false };

    printf("Parcours en profondeur : ");
    for (int s = 0; s < graph->Nbsommet; s++) {
        if (!visited[s]) {
            explorer(graph, s, visited);
        }
    }
    printf("\n");
}*/



