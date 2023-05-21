#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



typedef struct Noeud {
    int sommet;
    int poids;
    struct Noeud* suivant;
} Noeud;

// Structure de graphe
typedef struct {
    int sommetDeDepart;
    int sommetArrive;
    int Nbsommet;
    int** MatriceAdjacente;
    Noeud** listeSuccesseurs;
} Graphe;

void initializeGraph(Graphe* graph);
void Ajout_Arc(Graphe* graph, int sommet, int successeurs);
void Ajout_Arc2(Graphe* graph, int sommet, int successeurs, int poids);
void LireGraphe(Graphe* graph, FILE* fichier);
void LireGraphe2(Graphe* graph, FILE* fichier2);
void Afficher_Matrice_Adjacente(Graphe* graph);
void convertirMatriceEnListeSuccesseurs(Graphe* graph);
void Afficher_Successeur(Graphe* graph);
void parcoursProfondeur(Graphe* graph, int sommet, bool* visite);
void rechercheEnProfondeur(Graphe* graph);



#endif 
