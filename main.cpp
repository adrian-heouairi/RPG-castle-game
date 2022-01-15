#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <random>

using namespace std;

string prompt = "> ";
string prompt2 = ">> ";

char getChar() {
    system("stty raw");
    char c = getchar();
    system("stty cooked");

    return c;
}

int main() {
    string nom_du_joueur;

    cout << "Entrez le nom du joueur :" << endl << prompt;
    getline(cin, nom_du_joueur);

    cout << "Choisissez votre type de personnage (entrez un chiffre) :" << endl;
    cout << "1 : Moine" << endl;
    cout << "2 : Guerrier" << endl;
    cout << "3 : Sorcière" << endl;
    cout << "4 : Amazone" << endl;

    int choix_de_classe = 0;
    do {
        cout << prompt;
        cin >> choix_de_classe;
    } while (choix_de_classe < 1 || choix_de_classe > 4);

    Personnage *joueur;
    joueur->setPosI(0);
    joueur->setPosJ(0);
    vector<vector<Piece *>> carte;
    vector<Personnage *> ennemis;

    Piece *piece_actuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
    int numero_tour = 1;

    while (1) {
        vector <Personnage *> ennemis_dans_la_meme_piece;
        for (Personnage *ennemi : ennemis) {
            if (joueur->getPosI() == ennemi->getPosI() && joueur->getPosJ() == ennemi->getPosJ()) {
                ennemis_dans_la_meme_piece.push_back(ennemi);
            }
        }
        for (Personnage *ennemi : ennemis_dans_la_meme_piece) {
            if (!combat(joueur, ennemi)) {
                cout << "Vous êtes mort" << endl;
                return;
            }
        }

        bool tour_fini = false;
        while (!tour_fini) {
            cout << "numéro_tour nom classe position santé habileté inventaire objets_pièce (ennemis) (escalier) aide : h" << endl;
            cout << prompt;

            char c = getChar();
            cout << endl;

            switch (c) {
            case 'z': case 'w':
                if (joueur->getPosI() > 0) {
                    joueur->setPosI(joueur->getPosI() - 1);
                    piece_actuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
                    tour_fini = true;
                }
                break;

            case 'q': case 'a':
                if (joueur->getPosJ() > 0) {
                    joueur->setPosJ(joueur->getPosJ() - 1);
                    piece_actuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
                    tour_fini = true;
                }
                break;

            case 's':
                if (joueur->getPosI() < carte.size() - 1) {
                    joueur->setPosI(joueur->getPosI() + 1);
                    piece_actuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
                    tour_fini = true;
                }
                break;

            case 'd':
                if (joueur->getPosJ() < carte.at(0).size() - 1) {
                    joueur->setPosJ(joueur->getPosJ() + 1);
                    piece_actuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
                    tour_fini = true;
                }
                break;

            case ' ':
                tour_fini = true;
                break;

            case 'h':
                cout << " Se déplacer : zqsd/wasd | Attendre : Espace | "
                "Utiliser un objet : u | "
                "Poser un objet : p | Ramasser un objet : r | Monter un escalier : e";
                break;

            case 'u':

                break;

            case 'p':

                break;

            case 'r':

                break;

            case 'e':

                break;

            case 'l':
                cout << "Voulez-vous vraiment quitter ? Oui : o | Non : Autre touche" << endl;
                cout << prompt2;
                if (getChar() == 'o') return;
                break;
            }

            cout << endl;
        }

        // Faire bouger les ennemis :
        for (Personnage *ennemi : ennemis) {
            bool action_effectuee = false;
            while (!action_effectuee) {
                random_device dev;
                mt19937 rng(dev());
                uniform_int_distribution<mt19937::result_type> dist5(1,5);
                int choix = dist5(rng);
                switch (choix) {
                case 1:
                    if (ennemi->getPosI() > 0) {
                        ennemi->setPosI(ennemi->getPosI() - 1);
                        action_effectuee = true;
                    }
                    break;

                case 2:
                    if (ennemi->getPosJ() > 0) {
                        ennemi->setPosJ(ennemi->getPosJ() - 1);
                        action_effectuee = true;
                    }
                    break;

                case 3:
                    if (ennemi->getPosI() < carte.size() - 1) {
                        ennemi->setPosI(ennemi->getPosI() + 1);
                        action_effectuee = true;
                    }
                    break;

                case 4:
                    if (ennemi->getPosJ() < carte.at(0).size() - 1) {
                        ennemi->setPosJ(ennemi->getPosJ() + 1);
                        action_effectuee = true;
                    }
                    break;

                case 5:
                    action_effectuee = true;
                    break;
                }
            }
        }

        numero_tour++;
    }
}
