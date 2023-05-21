#ifndef FONCTIONS_H
#define FONCTIONS_H

#include<stdio.h>
#include "structures2.h"

TypesGraphe lireFichierTypeSommet(const char* nomFichier);
CoutsTypes lireFichierType(const char* nomFichier);
Graph lireFichierTerrain(const char* nomFichier);
int trouverSommetMin(int distance[], int visite[], int n);
void dijkstra(Graph graphe, int debut, int fin);





#endif /* FONCTIONS_H */
