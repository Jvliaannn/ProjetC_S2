#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



typedef struct Noeud {
    int sommet;
    struct Noeud* suivant;
} Noeud;

// Structure de graphe
typedef struct {
    int sommetDeDepart;
    int sommetArrive;
    int Nbsommet;
    int** MatriceAdjacente;
    Noeud** listeSuccesseurs;
    
} Graph;

void initializeGraph(Graph* graph);
void addEdge(Graph* graph, int sommet, int successeurs);
void LireGraphe(Graph* graph, FILE* fichier);
void printAdjacencyMatrix(Graph* graph);
void convertirMatriceEnListeSuccesseurs(Graph* graph);
void printSuccessorList(Graph* graph);
void parcoursProfondeur(Graph* graph, int sommet, bool* visite);
void rechercheEnProfondeur(Graph* graph);



#endif
