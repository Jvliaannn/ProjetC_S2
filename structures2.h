#ifndef STRUCTURES2_H
#define STRUCTURES2_H

typedef struct {
    int identifiant;
    char nom[20];
} TypeSommet;

typedef struct Noeud {
    int sommet;
    struct Noeud* suivant;
} Noeud;

typedef struct {
    int sommetDeDepart;
    int sommetArrive;
    int Nbsommet;
    int** MatriceAdjacente;
    Noeud** listeSuccesseurs;
    TypeSommet* types;
} Graph;

typedef struct {
    TypeSommet* types;
    int nbTypes;
} TypesGraphe;

typedef struct {
    char nom[20];
    double cout;
} CoutType;

typedef struct {
    CoutType* couts;
    int nbCouts;
} CoutsTypes;

TypesGraphe lireFichierTypeSommet(const char* nomFichier);
CoutsTypes lireFichierType(const char* nomFichier);
Graph lireFichierTerrain(const char* nomFichier);
int trouverSommetMin(int distance[], int visite[], int n);
void dijkstra(Graph graphe, int debut, int fin);


#endif
