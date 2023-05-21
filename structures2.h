#ifndef STRUCTURES2_H
#define STRUCTURES2_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure représentant un type de sommet
typedef struct {
    int identifiant;
    char nom[20];
} TypeSommet;

// Structure représentant un noeud dans la liste des successeurs
typedef struct Noeud {
    int sommet;
    struct Noeud* suivant;
} Noeud;

// Structure représentant un graphe
typedef struct {
    int sommetDeDepart;
    int sommetArrive;
    int Nbsommet;
    int** MatriceAdjacente;
    Noeud** listeSuccesseurs;
    TypeSommet* types;
} Graph;

// Structure représentant les types de sommets d'un graphe
typedef struct {
    TypeSommet* types;
    int nbTypes;
} TypesGraphe;

// Structure représentant les coûts des types de sommets
typedef struct {
    char nom[20];
    double cout;
} CoutType;

// Structure représentant les coûts des types de sommets d'un graphe
typedef struct {
    CoutType* couts;
    int nbCouts;
} CoutsTypes;

// Prototypes des fonctions
TypesGraphe lireFichierTypeSommet(const char* nomFichier);
CoutsTypes lireFichierType(const char* nomFichier);
Graph lireFichierTerrain(const char* nomFichier);

#endif
