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

    cout << endl;

    return c;
}

int getRandomIntBetween(int a, int b) {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(a, b);
    return dist(rng);
}

bool combat(Personnage *joueur, Personnage *p2) {
    cout << "Combat contre " << p2->getNom() << endl;

    while (joueur->getSante() > 0 && p2->getSante() > 0) {
        vector<Objet *> objetsUtilisablesEnCombat;
        for (Objet *o : joueur->getInventaire()) {
            if (o->isUtilisableEnCombat()) {
                objetsUtilisablesEnCombat.push_back(o);
            }
        }
        for (int i = 0; i < objetsUtilisablesEnCombat.size(); i++) {
            cout << i + 1 << " : " << objetsUtilisablesEnCombat.at(i)->getNom() << endl;
        }
        cout << "e : Frapper au poing" << endl;
        cout << "Santé du joueur : " << joueur->getSante() <<
        " | Santé de l'ennemi : " << p2->getSante() << endl;
        cout << prompt2;

        bool tour_combat_fini = false;
        while (!tour_combat_fini) {
            char c = getChar();
            if ('1' <= c && c <= '9') {
                int index = c - 48 - 1;
                if (index < objetsUtilisablesEnCombat.size()) {
                    objetsUtilisablesEnCombat.at(index)->utiliserEnCombat();
                    tour_combat_fini = true;
                }
            }
            else if (c == 'e') {
                // Ici joueur frappe p2 au poing
                tour_combat_fini = true;
            }
            else {
                cout << "Erreur : tapez autre chose" << endl;
            }
        }

        if (joueur->getSante() <= 0 || p2->getSante() <= 0) break;

        // Ici, p2 frappe joueur
    }

    if (joueur->getSante() <= 0) {
        return false;
    }

    for (int i = 0; i < ennemis.size(); i++) {
        if (ennemis.at(i) == p2) {
            ennemis.erase(ennemis.begin()+1);
        }
    }
    delete p2;
    return true;
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
    joueur->setNom(nom_du_joueur);
    joueur->setPosI(0);
    joueur->setPosJ(0);
    vector<vector<Piece *>> carte;
    // Ici mettre des objets aléatoirement dans certaines pièces de la carte
    // Une des pièces doit avoir un escalier
    int maxI;
    int maxJ;
    vector<Personnage *> ennemis;

    Piece *piece_actuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
    int numero_tour = 1;

    while (1) {
        // Combat avec les ennemis dans la pièce
        vector<Personnage *> ennemis_dans_la_meme_piece;
        for (Personnage *ennemi : ennemis) {
            if (joueur->getPosI() == ennemi->getPosI() && joueur->getPosJ() == ennemi->getPosJ()) {
                ennemis_dans_la_meme_piece.push_back(ennemi);
            }
        }
        if (ennemis_dans_la_meme_piece.size() > 0) {
            cout << "Vous devez combattre " << ennemis_dans_la_meme_piece.size() <<
            " ennemi(s) dans cette pièce" << endl;
            for (Personnage *ennemi : ennemis_dans_la_meme_piece) {
                if (!combat(joueur, ennemi)) {
                    cout << "Vous êtes mort" << endl;
                    return;
                }
            }
        }
        // Fin Combat avec les ennemis dans la pièce

        bool tour_fini = false;
        while (!tour_fini) {
            cout << "Tour " << numero_tour << " | "
            "Etage " << etage << " | "
            "Nom : " << joueur->getNom() << " | "
            "Classe : "
            "Position : (" << joueur->getPosI() << "," << joueur->getPosJ() << ") | "
            "Santé : " << joueur->getSante() << " | "
            "Habileté : " << joueur->getHabilete() << " | "
            "Inventaire [";

            for (int i = 0; i < joueur->getInventaire().size(); i++) {
                if (i != 0) {
                    cout << ", ";
                }
                cout << joueur->getInventaire().at(i)->getNom();
            }
            cout << "] | "

            "Objets dans cette pièce [";

            for (int i = 0; i < piece_actuelle->getObjets().size(); i++) {
                if (i != 0) {
                    cout << ", ";
                }
                cout << piece_actuelle->getObjets().at(i)->getNom();
            }
            cout << "] | "

            //"(escalier)"
            "Aide : appuyez sur h" << endl;

            cout << prompt;

            char c = getChar();

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
                vector<Objet *> objetsUtilisables;
                for (Objet *o : joueur->inventaire) {
                    if (o->isUtilisable()) {
                        objetsUtilisables.push_back(o);
                    }
                }

                if (objetsUtilisables.size() > 0) {
                    for (int i = 0; i < objetsUtilisables.size(); i++) {
                        cout << i + 1 << " : " << objetsUtilisables.at(i)->getNom() << endl;
                    }
                    cout << "Autre touche : Retour" << endl;
                    cout << prompt2;
                    int choix = getChar() - 48 - 1;
                    if (0 <= choix && choix < objetsUtilisables.size()) {
                        // On enlève l'objet de l'inventaire car on l'utilise
                        for (int i = 0; i < joueur->getInventaire().size(); i++) {
                            if (joueur->getInventaire().at(i) == objetsUtilisables.at(choix)) {
                                joueur->getInventaire().erase(joueur->getInventaire().begin() + i);
                            }
                        }

                        objetsUtilisables.at(choix)->utiliser();
                        delete objetsUtilisables.at(choix);
                        tour_fini = true;
                    }
                }
                break;

            case 'p':
                if (joueur->getInventaire().size() > 0) {
                    for (int i = 0; i < joueur->getInventaire().size(); i++) {
                        cout << i + 1 << " : " << joueur->getInventaire().at(i)->getNom() << endl;
                    }
                    cout << "Autre touche : Retour" << endl;
                    cout << prompt2;
                    int choix = getChar() - 48 - 1;
                    if (0 <= choix && choix < joueur->getInventaire().size()) {
                        piece_actuelle->ajouterObjet(joueur->getInventaire().at(choix));
                        joueur->getInventaire().erase(joueur->getInventaire().begin() + choix);
                        tour_fini = true;
                    }
                }
                break;

            case 'r':
                if (piece_actuelle->getObjets()->size() > 0 && joueur->getInventaire().size() < 4) {
                    cout << "Tapez un nombre puis entrée, ou autre chose pour annuler :";
                    for (int i = 0; i < piece_actuelle->getObjets()->size(); i++) {
                        cout << i + 1 << " : " << piece_actuelle->getObjets()->at(i)->getNom() << endl;
                    }
                    cout << prompt2;
                    int choix;
                    cin >> choix;
                    choix--;
                    if (0 <= choix && choix < piece_actuelle->getObjets()->size()) {
                        joueur->getInventaire().push_back(piece_actuelle->getObjets()->at(choix));
                        piece_actuelle->enleverObjet(piece_actuelle->getObjets()->at(choix));
                        tour_fini = true;
                    }
                }
                break;

            case 'e':
                if (piece_actuelle->aEscalier()) {
                    for (Personnage *e : ennemis) {
                        delete e;
                    }
                    ennemis.clear();
                    // Ici détruire tous les objets dans les pièces
                    // Ici regénérer une carte
                    joueur->setPosI(0);
                    joueur->setPosJ(0);
                    piece_actuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
                    continue;
                }
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
                int choix = getRandomIntBetween(1, 5);
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
                    
                default:
                    return 1;
                    break;
                }
            }
        }

        // Apparition aléatoire d'un ennemi avec 5 % de probabilité
        if (getRandomIntBetween(1, 100) <= 5) {
            Personnage *nouvelEnnemi;
            nouvelEnnemi->setPosI(getRandomIntBetween(0, maxI));
            nouvelEnnemi->setPosJ(getRandomIntBetween(0, maxJ));
            ennemis.push_back(nouvelEnnemi);
        }

        numero_tour++;
    }
}
