#ifndef FONCTIONS_H
#define FONCTIONS_H

#include<stdio.h>
#include "structures2.h"

TypesGraphe lireFichierTypeSommet1(const char* typeSommet1);
CoutsTypes lireFichierType1(const char* type1);
Graph lireFichierTerrain1(const char* terrain1);
int trouverSommetMin(int distance[], int visite[], int n);
void dijkstra(Graph graphe, int debut, int fin);






#endif /* FONCTIONS_H */
