#include "struct.h"

int main() 
{
    while (1) {  

        int choix;
        int choix2;
        printf("Veuillez choisir une mission :\n");
        printf("0. QUITTER\n");
        printf("1. Mission1\n");
        printf("2. Mission2\n");
        printf("3. Mission3\n");
        printf("4. Mission4\n");
        printf("Votre choix : ");       
        scanf("%d", &choix);
        Graph graph;

        FILE* fichier;
        FILE* fichier2;

        if (choix == 0) {
            printf("Au revoir !\n");
            break;  // Sortir de la boucle infinie et terminer le programme
        }

    switch (choix) {
            case 1:
                
                printf("Choisissez parmi ses deux options\n");
                printf("1) chemin permettant d’aller du sommet Début vers le sommet Fin tout en passant par le moins de sommets.\n");
                printf("2) chemin lemoins coûteux permettant d’aller du sommet Debut au sommet Fin.\n");
                scanf("%d", &choix2);

                if(choix2 == 1)
                {   
                    fichier = fopen("Donnees/planete1.txt", "r");
                    if (fichier == NULL) {
                        printf("Erreur lors de l'ouverture du fichier.\n");
                        exit(1);
                    }

                    printf("Lecture du fichier...\n");
                    LireGraphe(&graph, fichier);

                    printf("Matrice d'adjacence :\n");
                    printAdjacencyMatrix(&graph);

                    //Convertir la matrice d'adjacence en liste de successeurs
                    convertirMatriceEnListeSuccesseurs(&graph);

                    printf("Liste de successeurs :\n");
                    printSuccessorList(&graph);

                    rechercheEnProfondeur(&graph);

                    fclose(fichier);
                    
                }

                if(choix2 == 2)
                {
                    // Mission 2: Algorithme A*

                    fichier2 = fopen("Donnees/planete4.txt", "r");
                    if (fichier2 == NULL) {
                        printf("Erreur lors de l'ouverture du fichier.\n");
                        exit(1);
                    }

                    printf("Lecture du fichier...\n");
                    LireGraphe2(&graph, fichier2);

                    printf("Matrice d'adjacence :\n");
                    printAdjacencyMatrix(&graph);

                    //Convertir la matrice d'adjacence en liste de successeurs
                    convertirMatriceEnListeSuccesseurs2(&graph);

                    printf("Liste de successeurs :\n");
                    printSuccessorList2(&graph);

                    AStar(&graph);
                    
                    fclose(fichier2);

                }
                else{
     
                break;
                }
            case 2:


                break;
        }
    }
    return 0;
}
