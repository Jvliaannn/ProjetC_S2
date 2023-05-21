#include "structures2.h"

// Définition des constantes
#define INT_MAX 2000
#define MAX_LINE_LENGTH 100
#define MAX_VERTICES 100

// Fonction pour lire un fichier contenant les types de sommets
// et stocker les informations dans une structure TypesGraphe
TypesGraphe lireFichierTypeSommet(const char* nomFichier) {
    // Ouverture du fichier en mode lecture
    FILE* fichier = fopen(nomFichier, "r");
    
    // Déclaration et initialisation de la structure TypesGraphe
    TypesGraphe typesGraphe;
    
    if (fichier == NULL) {
        // Erreur lors de l'ouverture du fichier
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        typesGraphe.types = NULL;
        typesGraphe.nbTypes = 0;
        return typesGraphe;
    }
    
    // Déclaration d'une variable pour stocker chaque ligne du fichier
    char ligne[MAX_LINE_LENGTH];
    
    // Compter le nombre de lignes dans le fichier
    int nbLignes = 0;
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        nbLignes++;
    }
    
    // Allouer de la mémoire pour le tableau de types de sommets
    typesGraphe.types = (TypeSommet*) malloc(nbLignes * sizeof(TypeSommet));
    typesGraphe.nbTypes = nbLignes;
    
    // Retourner au début du fichier
    fseek(fichier, 0, SEEK_SET);
    
    // Lire et stocker les types de sommets
    int i = 0;
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        int numero;
        char nom[20];
        
        // Extraire les informations de chaque ligne
        sscanf(ligne, "%d %s", &numero, nom);
        
        // Stocker les informations dans la structure TypesGraphe
        typesGraphe.types[i].identifiant = numero;
        strncpy(typesGraphe.types[i].nom, nom, sizeof(typesGraphe.types[i].nom));
        
        i++;
    }
    
    // Fermeture du fichier
    fclose(fichier);
    
    // Retourner la structure TypesGraphe contenant les types de sommets
    return typesGraphe;
}


// Cette fonction lit les informations de coûts à partir d'un fichier texte
// et retourne une structure contenant ces informations.
// - nomFichier : le nom du fichier à lire
// - Retour : une structure CoutsTypes contenant les coûts lus
CoutsTypes lireFichierType(const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "r"); // Ouvre le fichier en mode lecture
    CoutsTypes coutsTypes; // Structure de données pour stocker les coûts
    
    if (fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n"); // Affiche un message d'erreur si l'ouverture du fichier échoue
        coutsTypes.couts = NULL;
        coutsTypes.nbCouts = 0;
        return coutsTypes;
    }
    
    char ligne[MAX_LINE_LENGTH]; // Variable pour stocker une ligne lue depuis le fichier
    int nbCouts = 0; // Variable pour stocker le nombre de coûts
    
    // Lire la première ligne pour obtenir le nombre de coûts
    if (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        sscanf(ligne, "%d", &nbCouts); // Lit le nombre de coûts à partir de la ligne
    }
    
    // Allouer de la mémoire pour le tableau de coûts
    coutsTypes.couts = (CoutType*) malloc(nbCouts * sizeof(CoutType));
    coutsTypes.nbCouts = nbCouts;
    
    // Lire et stocker les coûts
    for (int i = 0; i < nbCouts; i++) {
        if (fgets(ligne, sizeof(ligne), fichier) != NULL) {
            char nom[20];
            double cout;
            
            sscanf(ligne, "%s %lf", nom, &cout); // Lit le nom et le coût à partir de la ligne
            
            strncpy(coutsTypes.couts[i].nom, nom, sizeof(coutsTypes.couts[i].nom)); // Copie le nom dans la structure de données
            coutsTypes.couts[i].cout = cout; // Stocke le coût dans la structure de données
        }
    }
    
    fclose(fichier); // Ferme le fichier
    
    return coutsTypes; // Retourne la structure contenant les coûts lus
}


// Cette fonction lit un fichier représentant un terrain et construit un graphe à partir de celui-ci.
// Elle renvoie le graphe construit.
// Le paramètre nomFichier est une chaîne de caractères représentant le nom du fichier à lire.
Graph lireFichierTerrain(const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "r"); // Ouvre le fichier en mode lecture
    Graph graphe;
    
    if (fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n"); // Affiche un message d'erreur si l'ouverture du fichier a échoué
        graphe.sommetDeDepart = -1;
        graphe.sommetArrive = -1;
        graphe.Nbsommet = 0;
        graphe.MatriceAdjacente = NULL;
        graphe.listeSuccesseurs = NULL;
        
        return graphe;
    }
    
    char ligne[MAX_LINE_LENGTH];
    int sommetDeDepart = -1;
    int sommetArrive = -1;
    int nbSommets = 0;
    
    // Lire les premières lignes pour obtenir le sommet de départ, le sommet d'arrivée et le nombre de sommets
    if (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        sscanf(ligne, "Debut: %d", &sommetDeDepart);
    }
    
    if (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        sscanf(ligne, "Fin: %d", &sommetArrive);
    }
    
    if (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        sscanf(ligne, "%d", &nbSommets);
    }
    
    // Allouer de la mémoire pour la matrice adjacente
    int** matriceAdjacente = (int**) malloc(nbSommets * sizeof(int*));
    for (int i = 0; i < nbSommets; i++) {
        matriceAdjacente[i] = (int*) malloc(nbSommets * sizeof(int));
        for (int j = 0; j < nbSommets; j++) {
            matriceAdjacente[i][j] = -1; // Initialiser les coûts à -1 (pas de lien)
        }
    }
    
    // Lire et construire la matrice adjacente
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        int sommetOrigine, sommetDestination;
        sscanf(ligne, "%d -> %d", &sommetOrigine, &sommetDestination);
        
        matriceAdjacente[sommetOrigine][sommetDestination] = 1; // Utilisez le coût approprié ici (1 dans votre exemple)
    }
    
    fclose(fichier); // Ferme le fichier
    
    // Construire la liste des successeurs à partir de la matrice adjacente
    Noeud** listeSuccesseurs = (Noeud**) malloc(nbSommets * sizeof(Noeud*));
    for (int i = 0; i < nbSommets; i++) {
        listeSuccesseurs[i] = NULL;
        for (int j = 0; j < nbSommets; j++) {
            if (matriceAdjacente[i][j] != -1) {
                Noeud* nouveauNoeud = (Noeud*) malloc(sizeof(Noeud));
                nouveauNoeud->sommet = j;
                nouveauNoeud->suivant = listeSuccesseurs[i];
                listeSuccesseurs[i] = nouveauNoeud;
            }
        }
    }
    
    // Remplir la structure de graphe
    graphe.sommetDeDepart = sommetDeDepart;
    graphe.sommetArrive = sommetArrive;
    graphe.Nbsommet = nbSommets;
    graphe.MatriceAdjacente = matriceAdjacente;
    graphe.listeSuccesseurs = listeSuccesseurs;
    
    return graphe;
}



int trouverSommetMin(int distance[], int visite[], int n) {
    int min = INT_MAX;
    int minSommet = -1;
    
    for (int i = 0; i < n; i++) {
        if (visite[i] == 0 && distance[i] < min) {
            min = distance[i];
            minSommet = i;
        }
    }
    
    return minSommet;
}

void dijkstra(Graph graphe, int debut, int fin) {
    int n = graphe.Nbsommet;
    int distance[MAX_VERTICES];
    int visite[MAX_VERTICES];
    int precedent[MAX_VERTICES];
    
    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visite[i] = 0;
        precedent[i] = -1;
    }
    
    distance[debut] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int sommetCourant = trouverSommetMin(distance, visite, n);
        visite[sommetCourant] = 1;
        
        for (Noeud* successeur = graphe.listeSuccesseurs[sommetCourant]; successeur != NULL; successeur = successeur->suivant) {
            int sommetSuivant = successeur->sommet;
            int cout = graphe.MatriceAdjacente[sommetCourant][sommetSuivant];
            
            if (visite[sommetSuivant] == 0 && cout > 0 && cout < INT_MAX && graphe.types[sommetSuivant].identifiant != 6 && graphe.types[sommetSuivant].identifiant != 5) {
                if (distance[sommetCourant] + cout < distance[sommetSuivant]) {
                    distance[sommetSuivant] = distance[sommetCourant] + cout;
                    precedent[sommetSuivant] = sommetCourant;
                }
            }
        }
    }
    
    if (distance[fin] == INT_MAX) {
        printf("Il n'existe pas de chemin entre les sommets Début et Fin.\n");
    } else {
        printf("Chemin de coût minimum : ");
        int sommet = fin;
        printf("%d ", sommet);
        
        while (sommet != debut) {
            sommet = precedent[sommet];
            printf("<- %d ", sommet);
        }
        
        printf("\nCoût total : %d\n", distance[fin]);
    }
}
