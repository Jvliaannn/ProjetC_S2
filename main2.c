#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures2.h"
#include "fonctions.h"

int main() {
    // Tableaux contenant les noms des fichiers texte
    char* fichiersTypes[] = {"type1", "type2"};
    char* fichiersTypeSommets[] = {"typeSommet1", "typeSommet2"};
    char* fichiersTerrains[] = {"terrain1", "terrain2"};

    // Boucle pour traiter chaque fichier
    for (int i = 0; i < 2; i++) {
        // Lecture du fichier typesommet
        TypesGraphe typesGraphe = lireFichierTypeSommet1(fichiersTypeSommets[i]);
        // Vérification si la lecture a réussi
        if (typesGraphe.types != NULL) {
            printf("Contenu du fichier typesommet %d :\n", i+1);
            // Accéder aux types de sommets et à leur nombre
            for (int j = 0; j < typesGraphe.nbTypes; j++) {
                int identifiant = typesGraphe.types[j].identifiant;
                char nom[20];
                strncpy(nom, typesGraphe.types[j].nom, sizeof(nom));
                printf("Type de sommet %d : %s\n", identifiant, nom);
            }
            // Libérer la mémoire allouée pour les types de sommets
            free(typesGraphe.types);
        } else {
            printf("Erreur lors de la lecture du fichier typesommet %d\n", i+1);
        }

        // Lecture du fichier type
        CoutsTypes coutsTypes = lireFichierType1(fichiersTypes[i]);
        // Vérification si la lecture a réussi
        if (coutsTypes.couts != NULL) {
            printf("Contenu du fichier type %d :\n", i+1);
            // Accéder aux coûts des types de sommets et à leur nombre
            for (int j = 0; j < coutsTypes.nbCouts; j++) {
                int identifiant = j;
                char nom[20];
                strncpy(nom, coutsTypes.couts[j].nom, sizeof(nom));
                double cout = coutsTypes.couts[j].cout;
                printf("Coût du type de sommet %d (%s) : %lf\n", identifiant, nom, cout);
            }
            // Libérer la mémoire allouée pour les coûts
            free(coutsTypes.couts);
        } else {
            printf("Erreur lors de la lecture du fichier type %d\n", i+1);
        }

        // Lecture du fichier terrain
        Graph graphe = lireFichierTerrain1(fichiersTerrains[i]);
        // Vérification si la lecture a réussi
        if (graphe.MatriceAdjacente != NULL && graphe.listeSuccesseurs != NULL) {
            printf("Contenu du fichier terrain %d :\n", i+1);
            // Accéder aux informations du graphe
            int sommetDeDepart = graphe.sommetDeDepart;
            int sommetArrive = graphe.sommetArrive;
            int nbSommets = graphe.Nbsommet;            printf("Sommet de départ : %d\n", sommetDeDepart);
            printf("Sommet d'arrivée : %d\n", sommetArrive);
            printf("Nombre de sommets : %d\n", nbSommets);

            // Afficher la matrice adjacente
            printf("Matrice adjacente :\n");
            for (int j = 0; j < nbSommets; j++) {
                for (int k = 0; k < nbSommets; k++) {
                    printf("%d ", graphe.MatriceAdjacente[j][k]);
                }
                printf("\n");
            }

            // Afficher la liste des successeurs
            printf("Liste des successeurs :\n");
            for (int j = 0; j < nbSommets; j++) {
                printf("Sommet %d :", j);
                Noeud* successeur = graphe.listeSuccesseurs[j];
                while (successeur != NULL) {
                    printf(" %d", successeur->sommet);
                    successeur = successeur->suivant;
                }
                printf("\n");
            }

            // Libérer la mémoire allouée pour la matrice adjacente et la liste des successeurs
            for (int j = 0; j < nbSommets; j++) {
                free(graphe.MatriceAdjacente[j]);
                Noeud* successeur = graphe.listeSuccesseurs[j];
                while (successeur != NULL) {
                    Noeud* suivant = successeur->suivant;
                    free(successeur);
                    successeur = suivant;
                }
            }
            free(graphe.MatriceAdjacente);
            free(graphe.listeSuccesseurs);
        } else {
            printf("Erreur lors de la lecture du fichier terrain %d\n", i+1);
        }

        // Appel à la fonction Dijkstra
        dijkstra(graphe, graphe.sommetDeDepart, graphe.sommetArrive);

        printf("\n");
    }

    return 0;
}


