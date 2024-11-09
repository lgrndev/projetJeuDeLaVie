#include <vector> // Inclusion de la bibliothèque standard vector
#include <iostream> // Inclusion de la bibliothèque standard iostream

using namespace std; // Utilisation de l'espace de noms standard

// Déclaration de la classe Grille
class Grille {
    
private:
    vector<vector<int> > grille; // Grille de cellules représentée par un vecteur de vecteurs d'entiers
    int nIteration; // Nombre d'itérations de la grille
    
public:
    // Constructeur de la classe Grille prenant en paramètre le nombre de colonnes et de lignes
    Grille(int nCol, int nRow);
    
    // Méthode pour obtenir le nombre d'itérations
    int getNIteration();
    
    // Méthode pour afficher la grille
    void displayGrille();
    
    // Méthode pour compter le nombre de voisins vivants d'une cellule donnée
    int countVoisin(int x, int y);
    
    // Méthode pour passer à la génération suivante de la grille
    void nextGeneration();
    
    // Méthode pour ajouter une cellule vivante à la position (x, y)
    void ajouterCelluleVivante(int x, int y);
    
    // Méthode pour ajouter une cellule morte à la position (x, y)
    void ajouterCelluleMorte(int x, int y);
    
    // Méthode pour répartir aléatoirement des cellules vivantes dans la grille selon une probabilité donnée
    void repartitionAleatoire(double proba);

    // Méthode pour obtenir la valeur d'une cellule à la position (x, y)
    int getCellule(int x, int y);
};