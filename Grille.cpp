#include "Grille.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

Grille::Grille(int nCol, int nRow) {
    grille = vector<vector<int> > (nRow, vector<int> (nCol, 0));
    nIteration = 0;
};

int Grille::getNIteration() {
    return nIteration;
};

void Grille::displayGrille() {
    for(int i = 0; i < grille.size(); i++) {
        for(int j = 0; j < grille[i].size(); j++) {
            cout << grille[i][j] << " ";
        }
        cout << endl;
    }
};

void Grille::ajouterCelluleVivante(int x, int y) {
    grille[x][y] = 1;
};

void Grille::ajouterCelluleMorte(int x, int y) {
    grille[x][y] = 0;
};

int Grille::getCellule(int x, int y) {
    return grille[x][y];
};

int Grille::countVoisin(int x, int y) {
    int count = 0;
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (i >= 0 && i < grille.size() && j >= 0 && j < grille[i].size() && !(i == y && j == x)) {
                count += grille[i][j];
            }
        }
    }
    return count;
};



void Grille::repartitionAleatoire(double proba) {
    for (int i = 0;i < grille.size();i++) {
        for (int j = 0; j < grille[i].size();j++) {
            if ((double)rand() / RAND_MAX < proba) {
                grille[i][j] = 1;
            };
        }
    }
};


void Grille::nextGeneration() {
    vector<vector<int> > newGrille = grille;
    for (int i = 0; i < grille.size(); i++) {
        for (int j = 0; j < grille[i].size(); j++) {
            int voisins = countVoisin(j, i);

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

    grille = newGrille;
    nIteration++;
};