#include "struct.h"

int main() 
{
    FILE* fichier = fopen("Donnees/planete1.txt", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }

    printf("Lecture du fichier...\n");

    Graph graph;
    LireGraphe(&graph, fichier);

    printf("Matrice d'adjacence :\n");
    printAdjacencyMatrix(&graph);

        // Convertir la matrice d'adjacence en liste de successeurs
    convertirMatriceEnListeSuccesseurs(&graph);

    printf("Liste de successeurs :\n");
    printSuccessorList(&graph);

    rechercheEnProfondeur(&graph);

    /*bool* visite = (bool*)calloc(graph.Nbsommet, sizeof(bool));
    parcoursProfondeur(&graph, graph.sommetDeDepart, visite, graph.sommetArrive);
    printf("\n");*/


    fclose(fichier);
    

    return 0;
}
