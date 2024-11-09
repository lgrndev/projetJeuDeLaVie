#include "Grille.hpp"
#include <iostream>
#include <vector>

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
}
