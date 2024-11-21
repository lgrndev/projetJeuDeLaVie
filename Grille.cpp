#include "Grille.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

Grille::Grille(int nCol, int nRow) {
    grille = vector<vector<int> > (nRow, vector<int> (nCol, 0)); // On initialise un vecteur dans un vecteur pour faire un tableau en 2 dimensions.
    nIteration = 0; // On initialise le nombre d'itérations à 0.
};

int Grille::getNIteration() {
    return nIteration; // On retourne le nombre d'itérations.
};

void Grille::displayGrille() {
    // On fait une double boucle for. Pour afficher chaque case de la grille.
    for(int i = 0; i < grille.size(); i++) { // grille.size() retourne le nombre de lignes.
        for(int j = 0; j < grille[i].size(); j++) { // grille[i].size() retourne le nombre de colonnes.
            cout << grille[i][j] << " "; // on affiche le contenu de la cellule : 0 pour morte 1 pour vivante.
        }
        cout << endl; // On retourne à la ligne.
    }
};

void Grille::ajouterCelluleVivante(int x, int y) {
    grille[x][y] = 1; // On ajoute une cellule vivante à la coordonnée x et y.
};

void Grille::ajouterCelluleMorte(int x, int y) {
    grille[x][y] = 0; // On ajoute une cellule morte à la coordonnée x et y.
};

int Grille::getCellule(int x, int y) {
    return grille[x][y]; // On retourne la valeur de la cellule à la coordonnée x et y.
};

int Grille::countVoisin(int x, int y) {
    int count = 0; // On initialise le nombre de voisin à 0.
    // On fait une double boucle for pour balayer tout le tableau.
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (i >= 0 && i < grille.size() && j >= 0 && j < grille[i].size() && !(i == y && j == x)) { // Conditions pour ne pas dépasser du tableau. Ou ne pas compter la cellule regardée.
                count += grille[i][j]; // On ajoute le contenu de la cellule : 1 pour vivante et 0 pour morte.
            }
        }
    }
    return count; // On retourne le nombre final de voisins de la cellule à la coordonée x et y.
};



void Grille::repartitionAleatoire(double proba) {
    // On fait une double boucle for pour balayer tout le tableau.
    for (int i = 0;i < grille.size();i++) {
        for (int j = 0; j < grille[i].size();j++) {
            if ((double)rand() / RAND_MAX < proba) { // Condition pour rajouter une cellule vivante. Inférieur à la proba choisie.
                grille[i][j] = 1; // On ajoute une cellule vivante si la condition est vérifiée.
            };
        }
    }
};


void Grille::nextGeneration() {
    vector<vector<int> > newGrille = grille; // On crée une grille temporaire.
    // On fait une double boucle for pour balayer tout le tableau.
    for (int i = 0; i < grille.size(); i++) {
        for (int j = 0; j < grille[i].size(); j++) {
            // On récupere le nombre de voisins.
            int voisins = countVoisin(j, i);

            // Conditions pour rajouter une cellule vivante ou morte.
            if (grille[i][j] == 1) {
                if (voisins < 2 || voisins > 3) {
                    newGrille[i][j] = 0; 
                }
            } else { 
                if (voisins == 3) {
                    newGrille[i][j] = 1; 
                }
            }
        }
    }


    // On remplace la grille par la grille temporaire.
    grille = newGrille;
    // On rajoute 1 au nombre d'itérations.
    nIteration++;
};
