#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <random>

using namespace std;

Personnage *joueur;
vector<vector<Piece *>> carte;
int maxI;
int maxJ;
Piece *pieceActuelle;
vector<Personnage *> ennemis;
int numeroTour = 1;

string prompt = "> ";
string prompt2 = ">> ";
string separateur = " | ";

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

// Retourne vrai en cas de victoire du joueur
bool combat(Personnage *ennemi) {
    cout << "Combat contre " << ennemi->getNom() << endl;

    while (joueur->getSante() > 0 && ennemi->getSante() > 0) {
        vector<Objet *> objetsUtilisablesEnCombat;
        for (Objet *o : joueur->getInventaire()) {
            if (o->isUtilisableEnCombat(joueur)) {
                objetsUtilisablesEnCombat.push_back(o);
            }
        }
        for (int i = 0; i < objetsUtilisablesEnCombat.size(); i++) {
            cout << i + 1 << " : " << objetsUtilisablesEnCombat.at(i)->getNom() << endl;
        }
        cout << "e : Frapper au poing" << endl;
        cout << "Santé du joueur : " << joueur->getSante() <<
        " | Santé de l'ennemi : " << ennemi->getSante() << endl;
        cout << prompt2;

        bool tourCombatDuJoueurFini = false;
        while (!tourCombatDuJoueurFini) {
            char c = getChar();
            if ('1' <= c && c <= '9') {
                int index = c - 48 - 1;
                if (index < objetsUtilisablesEnCombat.size()) {
                    objetsUtilisablesEnCombat.at(index)->utiliserEnCombat();
                    // Ici, éventuellement enlever l'objet de l'inventaire du joueur
                    tourCombatDuJoueurFini = true;
                }
            }
            else if (c == 'e') {
                // Ici joueur frappe ennemi au poing
                tourCombatDuJoueurFini = true;
            }
            else {
                cout << "Erreur : tapez autre chose" << endl;
            }
        }

        if (joueur->getSante() <= 0 || ennemi->getSante() <= 0) break;

        // Ici, ennemi frappe joueur
    }

    if (joueur->getSante() <= 0) {
        return false;
    }

    for (int i = 0; i < ennemis.size(); i++) {
        if (ennemis.at(i) == ennemi) {
            ennemis.erase(ennemis.begin() + i);
        }
    }
    delete ennemi;
    return true;
}

bool combatEnnemisDansLaMemePiece() {
    vector<Personnage *> ennemisDansLaMemePiece;
    for (Personnage *ennemi : ennemis) {
        if (joueur->getPosI() == ennemi->getPosI() && joueur->getPosJ() == ennemi->getPosJ()) {
            ennemisDansLaMemePiece.push_back(ennemi);
        }
    }
    if (ennemisDansLaMemePiece.size() > 0) {
        cout << "Vous devez combattre " << ennemisDansLaMemePiece.size() <<
        " ennemi(s) dans cette pièce" << endl;
        for (Personnage *ennemi : ennemisDansLaMemePiece) {
            if (!combat(ennemi)) {
                cout << "Vous êtes mort" << endl;
                return false;
            }
        }
    }

    return true;
}

void ecranTitre() {
    string nomDuJoueur;

    cout << "Entrez le nom du joueur :" << endl << prompt;
    getline(cin, nomDuJoueur);

    cout << "Choisissez votre type de personnage (entrez un chiffre) :" << endl;
    cout << "1 : Moine" << endl;
    cout << "2 : Guerrier" << endl;
    cout << "3 : Sorcière" << endl;
    cout << "4 : Amazone" << endl;

    int choixDeClasse = 0;
    do {
        cout << prompt;
        cin >> choixDeClasse;
    } while (choixDeClasse < 1 || choixDeClasse > 4);

    joueur->setNom(nomDuJoueur);
    joueur->setPosI(0);
    joueur->setPosJ(0);
    // Ici mettre des objets aléatoirement dans certaines pièces de la carte
    // Une des pièces doit avoir un escalier
    // Ici set maxI et maxJ

    pieceActuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
}

void afficherEtat() {
    cout << "Tour " << numeroTour;
    cout << separateur;
    cout << "Etage " << etage;
    cout << separateur;
    cout << "Nom : " << joueur->getNom();
    cout << separateur;
    cout << "Classe : ";
    cout << separateur;
    cout << "Position : (" << joueur->getPosI() << "," << joueur->getPosJ() << ")";
    cout << separateur;
    cout << "Santé : " << joueur->getSante();
    cout << separateur;
    cout << "Habileté : " << joueur->getHabilete();
    cout << separateur;

    cout << "Inventaire : [";
    for (int i = 0; i < joueur->getInventaire().size(); i++) {
        if (i != 0) {
            cout << ", ";
        }
        cout << joueur->getInventaire().at(i)->getNom();
    }
    cout << "]";

    cout << separateur;

    cout << "Objets dans cette pièce : [";
    for (int i = 0; i < pieceActuelle->getInventaire().size(); i++) {
        if (i != 0) {
            cout << ", ";
        }
        cout << pieceActuelle->getInventaire().at(i)->getNom();
    }
    cout << "]";

    cout << separateur;

    cout << "Aide : appuyez sur h";
    
    if (pieceActuelle->aEscalier()) {
        cout << separateur;
        cout << "Monter escalier : appuyez sur e";
    }

    cout << endl;
}

bool utiliserObjetHorsCombat() {
    vector<Objet *> objetsUtilisables;
    for (Objet *o : joueur->getInventaire()) {
        if (o->isUtilisableHorsCombat(joueur)) {
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
            joueur->inventaireEnlever(objetsUtilisables.at(choix));
            objetsUtilisables.at(choix)->utiliser();
            delete objetsUtilisables.at(choix);
            return true;
        }
    }
    return false;
}

bool poserObjet() { // TODO ici vérifier pieceActuelle->inventaireADeLaPlace() ?
    if (joueur->getInventaire().size() > 0) {
        for (int i = 0; i < joueur->getInventaire().size(); i++) {
            cout << i + 1 << " : " << joueur->getInventaire().at(i)->getNom() << endl;
        }
        cout << "Autre touche : Retour" << endl;
        cout << prompt2;
        int choix = getChar() - 48 - 1;
        if (0 <= choix && choix < joueur->getInventaire().size()) {
            pieceActuelle->inventaireAjouter(joueur->getInventaire().at(choix));
            joueur->inventaireEnlever(joueur->getInventaire().at(choix));
            return true;
        }
    }
    return false;
}

bool ramasserObjet() {
    if (pieceActuelle->getInventaire().size() > 0 && joueur->inventaireADeLaPlace()) {
        for (int i = 0; i < pieceActuelle->getInventaire().size(); i++) {
            cout << i + 1 << " : " << pieceActuelle->getInventaire().at(i)->getNom() << endl;
        }
        cout << "Tapez un nombre puis entrée, ou autre chose pour annuler :" << endl;
        cout << prompt2;
        int choix;
        cin >> choix;
        choix--;
        if (0 <= choix && choix < pieceActuelle->getInventaire().size()) {
            joueur->inventaireAjouter(pieceActuelle->getInventaire().at(choix));
            pieceActuelle->inventaireEnlever(pieceActuelle->getInventaire().at(choix));
            return true;
        }
    }
    return false;
}

bool monterEscalier() {
    if (pieceActuelle->aEscalier()) {
        for (Personnage *e : ennemis) {
            delete e;
        }
        ennemis.clear();
        // Ici détruire tous les objets dans les pièces
        // Ici regénérer une carte
        joueur->setPosI(0);
        joueur->setPosJ(0);
        pieceActuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
        return true;
    }
    return false;
}

void faireBougerLesEnnemis() {
    for (Personnage *ennemi : ennemis) {
        bool actionEffectuee = false;
        while (!actionEffectuee) {
            int choix = getRandomIntBetween(1, 5);
            switch (choix) {
            case 1:
                if (ennemi->getPosI() > 0) {
                    ennemi->setPosI(ennemi->getPosI() - 1);
                    actionEffectuee = true;
                }
                break;

            case 2:
                if (ennemi->getPosJ() > 0) {
                    ennemi->setPosJ(ennemi->getPosJ() - 1);
                    actionEffectuee = true;
                }
                break;

            case 3:
                if (ennemi->getPosI() < maxI) {
                    ennemi->setPosI(ennemi->getPosI() + 1);
                    actionEffectuee = true;
                }
                break;

            case 4:
                if (ennemi->getPosJ() < maxJ) {
                    ennemi->setPosJ(ennemi->getPosJ() + 1);
                    actionEffectuee = true;
                }
                break;

            case 5:
                actionEffectuee = true;
                break;
                
            default:
                cout << "Erreur";
                break;
            }
        }
    }
}

int main() {
    ecranTitre();

    while (1) {
        if (!combatEnnemisDansLaMemePiece()) {
            return;
        }

        bool tourDuJoueurFini = false;
        while (!tourDuJoueurFini) {
            afficherEtat();

            cout << prompt;

            char c = getChar();

            switch (c) {
            case 'z': case 'w':
                if (joueur->getPosI() > 0) {
                    joueur->setPosI(joueur->getPosI() - 1);
                    pieceActuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
                    tourDuJoueurFini = true;
                }
                break;

            case 'q': case 'a':
                if (joueur->getPosJ() > 0) {
                    joueur->setPosJ(joueur->getPosJ() - 1);
                    pieceActuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
                    tourDuJoueurFini = true;
                }
                break;

            case 's':
                if (joueur->getPosI() < maxI) {
                    joueur->setPosI(joueur->getPosI() + 1);
                    pieceActuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
                    tourDuJoueurFini = true;
                }
                break;

            case 'd':
                if (joueur->getPosJ() < maxJ) {
                    joueur->setPosJ(joueur->getPosJ() + 1);
                    pieceActuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
                    tourDuJoueurFini = true;
                }
                break;

            case ' ':
                tourDuJoueurFini = true;
                break;

            case 'h':
                cout << " Se déplacer : zqsd/wasd | Attendre : Espace | "
                "Utiliser un objet : u | "
                "Poser un objet : p | Ramasser un objet : r | Monter un escalier : e";
                break;

            case 'u':
                if (utiliserObjetHorsCombat()) {
                    tourDuJoueurFini = true;
                }
                break;

            case 'p':
                if (poserObjet()) {
                    tourDuJoueurFini = true;
                }
                break;

            case 'r':
                if (ramasserObjet()) {
                    tourDuJoueurFini = true;
                }
                break;

            case 'e':
                if (monterEscalier()) {
                    tourDuJoueurFini = true;
                }
                break;

            case 'l':
                cout << "Voulez-vous vraiment quitter ? Oui : o | Non : Autre touche" << endl;
                cout << prompt2;
                if (getChar() == 'o') {
                    return;
                }
                break;

            default:
                cout << "Erreur";
                break;
            }

            cout << endl;
        }

        faireBougerLesEnnemis();

        // Apparition aléatoire d'un ennemi avec 5 % de probabilité
        if (getRandomIntBetween(1, 100) <= 5) {
            Personnage *nouvelEnnemi;
            nouvelEnnemi->setPosI(getRandomIntBetween(0, maxI));
            nouvelEnnemi->setPosJ(getRandomIntBetween(0, maxJ));
            ennemis.push_back(nouvelEnnemi);
        }

        numeroTour++;
    }
}
