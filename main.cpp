#include <SFML/Graphics.hpp>
#include "Grille.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Étape 1 : Initialisation
    int nCols, nRows;
    do {
        cout << "Entrez le nombre de colonnes : ";
        cin >> nCols;

        if (cin.fail()) { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ce n'est pas une entrée valide !" << endl;
        } else if (nCols <= 0) {
            cout << "Le nombre de colonnes doit être un entier strictement positif !" << endl;
        }
    } while (nCols <= 0 || cin.fail());



    do {
        cout << "Entrez le nombre de lignes : ";
        cin >> nRows;

        if (cin.fail()) { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ce n'est pas une entrée valide !" << endl;
        } else if (nRows <= 0) {
            cout << "Le nombre de lignes doit être un entier strictement positif !" << endl;
        }
    } while (nRows <= 0 || cin.fail());


    Grille grille(nCols, nRows);

    char choix;
    cout << "Voulez-vous une génération aléatoire (a) ou manuelle (m) ? ";
    cin >> choix;

    if (choix == 'a') {
        double proba;
        cout << "Entrez la probabilité pour une cellule vivante (entre 0 et 1) : ";
        cin >> proba;
        grille.repartitionAleatoire(proba);
    } else if (choix == 'm') {
        int x;
        int y;
        cout << "Entrez les coordonnées des cellules vivantes (-1 -1 pour arrêter) : " << endl;
        while (true) {
            cout << "x y : ";
            cin >> x >> y;
            if (x == -1 && y == -1) break;
            if (x >= 0 && x < nRows && y >= 0 && y < nCols) {
                grille.ajouterCelluleVivante(x, y);
            } else {
                cout << "Coordonnées invalides !" << endl;
            }
        }
    } else {
        cout << "Entrée invalide, arrêt du programme";
        return 0;
    };

    cout << "Grille initiale :" << endl;
    grille.displayGrille();

    // Création de la fenêtre SFML
    int cellSize = 20;
    sf::RenderWindow window(sf::VideoMode(nCols * cellSize, nRows * cellSize), "Jeu de la Vie");

    bool continuer = true;
    while (window.isOpen() && continuer) {
        // Étape 2 : Boucle principale
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        grille.nextGeneration();

        // Affichage graphique
        window.clear(sf::Color::Black);
        for (int y = 0; y < nRows; y++) {
            for (int x = 0; x < nCols; x++) {
                sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
                cell.setPosition(x * cellSize, y * cellSize);
                if (grille.getCellule(y, x) == 1) {
                    cell.setFillColor(sf::Color::Green);
                } else {
                    cell.setFillColor(sf::Color::Black);
                }
                window.draw(cell);
            }
        }
        window.display();

        // Affichage console (A enlever)
        cout << "Génération : " << grille.getNIteration() << endl;

        // Interaction utilisateur
        do {
            cout << "Continuer ? (o/n) : ";
            cin >> choix;

            if (choix == 'n') {
                continuer = false;
            } else if(choix != 'n' && choix != 'o') {
                cout << "Entrée invalide, veuillez répondre par 'o' ou 'n'.\n";
            }
        } while (choix != 'o' && choix != 'n');

    }
    return 0;
}
