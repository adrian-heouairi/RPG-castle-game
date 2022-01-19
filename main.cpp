#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <random>

#include "Objet.hpp"
#include "Personnage.hpp"
#include "Piece.hpp"

#include "Moine.hpp"
#include "Guerrier.hpp"
#include "Sorciere.hpp"
#include "Amazone.hpp"

#include "Baton.hpp"
#include "Epee.hpp"
#include "BaguetteMagique.hpp"
#include "Arc.hpp"

#include "PotionDeSoin.hpp"
#include "PotionDePoison.hpp"

#include "CleDeTeleportation.hpp"

using namespace std;

const int TAILLE_MIN_CARTE = 5;
const int TAILLE_MAX_CARTE = 15;

// Variables globales qui contiennent l'état du jeu
Personnage *joueur; // Instancié dans ecranTitre()
vector<vector<Piece *>> carte;
int maxI;
int maxJ;
Piece *pieceActuelle;
vector<Personnage *> ennemis;
int numeroTour = 1;
int etage = 0;

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

// Retourne true en cas de survie du joueur
bool combatEnnemisDansLaMemePiece() {
    vector<Personnage *> ennemisDansLaMemePiece;
    for (Personnage *ennemi : ennemis) {
        if (joueur->getPosI() == ennemi->getPosI() && joueur->getPosJ() == ennemi->getPosJ()) {
            ennemisDansLaMemePiece.push_back(ennemi);
        }
    }
    
    if (ennemisDansLaMemePiece.size() == 0) {
        return true;
    }

    cout << "Vous devez combattre " << ennemisDansLaMemePiece.size() <<
    " ennemi(s) dans cette pièce" << endl;
    
    for (Personnage *ennemi : ennemisDansLaMemePiece) {
        cout << "Combat contre " << ennemi->getNom() << endl;

        cout << "Santé : " << joueur->getSante();
        cout << separateur;
        cout << "Habileté : " << joueur->getHabilete();
        cout << separateur;
        cout << "Santé de l'ennemi : " << ennemi->getSante() << endl;

        while (joueur->getSante() > 0 && ennemi->getSante() > 0) {
            vector<Objet *> objetsUtilisablesEnCombat;
            for (Objet *o : joueur->getInventaire()) {
                if (o->isUtilisableEnCombat(joueur)) {
                    objetsUtilisablesEnCombat.push_back(o);
                }
            }
            
            for (int i = 0; i < (int)objetsUtilisablesEnCombat.size(); i++) {
                cout << i + 1 << " : " << objetsUtilisablesEnCombat.at(i)->getNom() << endl;
            }
            cout << "r : Frapper au poing" << endl;
            
            cout << prompt2;

            bool tourCombatDuJoueurFini = false;
            while (!tourCombatDuJoueurFini) {
                char c = getChar();
                if ('1' <= c && c <= '9') {
                    int index = c - 48 - 1;
                    if (index < (int)objetsUtilisablesEnCombat.size()) {
                        // Pour le cas où le joueur se téléporte
                        int posIAvant = joueur->getPosI();
                        int posJAvant = joueur->getPosJ();

                        objetsUtilisablesEnCombat.at(index)->utiliserEnCombat(joueur, ennemi);
                        if (objetsUtilisablesEnCombat.at(index)->isConsommable()) {
                           joueur->inventaireEnlever(objetsUtilisablesEnCombat.at(index));
                            delete objetsUtilisablesEnCombat.at(index);
                        }

                        // Le joueur s'est téléporté
                        if (posIAvant != joueur->getPosI() || posJAvant != joueur->getPosJ()) {
                            pieceActuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
                            return true;
                        }

                        tourCombatDuJoueurFini = true;
                    }
                }
                else if (c == 'r') {
                    // Ici joueur frappe ennemi au poing
                    ennemi->setSante(ennemi->getSante() - joueur->getDegatsAuPoing());
                    tourCombatDuJoueurFini = true;
                }
                else {
                    cout << "Erreur : tapez autre chose" << endl;
                }
            }

            if (joueur->getSante() <= 0 || ennemi->getSante() <= 0) break;

            // Ici, ennemi frappe joueur
            joueur->setSante(joueur->getSante() - ennemi->getDegatsAuPoing());
        }

        // Si le joueur a perdu
        if (joueur->getSante() <= 0) {
            cout << "Vous êtes mort" << endl;
            return false;
        }

        // Si le joueur a gagné, l'ennemi meurt et on passe au suivant
        for (int i = 0; i < (int)ennemis.size(); i++) {
            if (ennemis.at(i) == ennemi) {
                ennemis.erase(ennemis.begin() + i);
                break;
            }
        }
        delete ennemi;
    }

    // Le joueur a survécu à tous les combats
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

    if (choixDeClasse == 1) {
        joueur = new Moine{100};
        joueur->inventaireAjouter(new Baton{10});
    }
    else if (choixDeClasse == 2) {
        joueur = new Guerrier{120};
        joueur->inventaireAjouter(new Epee{8});
    }
    else if (choixDeClasse == 3) {
        joueur = new Sorciere{90};
        joueur->inventaireAjouter(new BaguetteMagique{13});
    }
    else if (choixDeClasse == 4) {
        joueur = new Amazone{100};
        joueur->inventaireAjouter(new Arc{10});
    }

    joueur->setNom(nomDuJoueur);
}

void genererEtage() {
    etage++;

    for (Personnage *e : ennemis) {
        delete e;
    }
    ennemis.clear();

    for (vector<Piece *> i : carte) {
        for (Piece *j : i) {
            delete j;
        }
    }
    carte.clear();

    maxI = getRandomIntBetween(TAILLE_MIN_CARTE - 1, TAILLE_MAX_CARTE - 1);
    maxJ = getRandomIntBetween(TAILLE_MIN_CARTE - 1, TAILLE_MAX_CARTE - 1);

    for (int i = 0; i <= maxI; i++) {
        carte.push_back(vector<Piece *>{});
    }

    for (int i = 0; i <= maxI; i++) {
        for (int j = 0; j <= maxJ; j++) {
            carte.at(i).push_back(new Piece);
        }
    }

    int escalierI = getRandomIntBetween(0, maxI);
    int escalierJ = getRandomIntBetween(0, maxJ);
    carte.at(escalierI).at(escalierJ)->setEscalier(true);

    for (int i = 0; i <= maxI; i++) {
        for (int j = 0; j <= maxJ; j++) {
            if (getRandomIntBetween(1, 100) <= 5) {
                int rand = getRandomIntBetween(1, 100);
                if (1 <= rand && rand <= 50) {
                    carte.at(i).at(j)->inventaireAjouter(new PotionDeSoin);
                }
                else if (51 <= rand && rand <= 80) {
                    int degatsArme = getRandomIntBetween(1, 50);

                    int rand2 = getRandomIntBetween(1, 100);
                    if (1 <= rand2 && rand2 <= 25) {
                        carte.at(i).at(j)->inventaireAjouter(new Baton{degatsArme});
                    }
                    else if (26 <= rand2 && rand2 <= 50) {
                        carte.at(i).at(j)->inventaireAjouter(new Epee{degatsArme});
                    }
                    else if (51 <= rand2 && rand2 <= 75) {
                        carte.at(i).at(j)->inventaireAjouter(new BaguetteMagique{degatsArme + 5});
                    }
                    else if (76 <= rand2 && rand2 <= 100) {
                        carte.at(i).at(j)->inventaireAjouter(new Arc{degatsArme});
                    }
                }
                else if (81 <= rand && rand <= 90) {
                    carte.at(i).at(j)->inventaireAjouter(new PotionDePoison);
                }
                else if (91 <= rand && rand <= 100) {
                    carte.at(i).at(j)->inventaireAjouter(new CleDeTeleportation);
                }
            }
        }
    }
    
    joueur->setPosI(getRandomIntBetween(0, maxI));
    joueur->setPosJ(getRandomIntBetween(0, maxJ));
    pieceActuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
}

void afficherEtat() {
    cout << "Tour " << numeroTour;
    cout << separateur;
    cout << "Etage " << etage;
    cout << separateur;
    cout << "Position : (" << joueur->getPosI() << "," << joueur->getPosJ() << ")";
    cout << separateur;
    cout << "Santé : " << joueur->getSante();
    cout << separateur;
    cout << "Habileté : " << joueur->getHabilete();
    cout << separateur;

    cout << "Inventaire : [";
    for (int i = 0; i < (int)joueur->getInventaire().size(); i++) {
        if (i != 0) {
            cout << ", ";
        }
        cout << joueur->getInventaire().at(i)->getNom();
    }
    cout << "]";

    cout << separateur;

    cout << "Objets dans cette pièce : [";
    for (int i = 0; i < (int)pieceActuelle->getInventaire().size(); i++) {
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
        cout << "Appuyez sur e pour monter l'escalier de cette pièce";
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
        for (int i = 0; i < (int)objetsUtilisables.size(); i++) {
            cout << i + 1 << " : " << objetsUtilisables.at(i)->getNom() << endl;
        }
        cout << "Autre touche : Retour" << endl;
        cout << prompt2;
        int choix = getChar() - 48 - 1;
        if (0 <= choix && choix < (int)objetsUtilisables.size()) {
            objetsUtilisables.at(choix)->utiliserHorsCombat(joueur);
            if (objetsUtilisables.at(choix)->isConsommable()) {
                joueur->inventaireEnlever(objetsUtilisables.at(choix));
                delete objetsUtilisables.at(choix);
            }
            return true;
        }
    }
    return false;
}

bool poserObjet() {
    if (joueur->getInventaire().size() > 0 && pieceActuelle->inventaireADeLaPlace()) {
        for (int i = 0; i < (int)joueur->getInventaire().size(); i++) {
            cout << i + 1 << " : " << joueur->getInventaire().at(i)->getNom() << endl;
        }
        cout << "Autre touche : Retour" << endl;
        cout << prompt2;
        int choix = getChar() - 48 - 1;
        if (0 <= choix && choix < (int)joueur->getInventaire().size()) {
            pieceActuelle->inventaireAjouter(joueur->getInventaire().at(choix));
            joueur->inventaireEnlever(joueur->getInventaire().at(choix));
            return true;
        }
    }
    return false;
}

bool ramasserObjet() {
    if (pieceActuelle->getInventaire().size() > 0 && joueur->inventaireADeLaPlace()) {
        for (int i = 0; i < (int)pieceActuelle->getInventaire().size(); i++) {
            cout << i + 1 << " : " << pieceActuelle->getInventaire().at(i)->getNom() << endl;
        }
        cout << "Tapez un nombre puis entrée, ou autre chose pour annuler :" << endl;
        cout << prompt2;
        int choix;
        cin >> choix;
        choix--;
        if (0 <= choix && choix < (int)pieceActuelle->getInventaire().size()) {
            joueur->inventaireAjouter(pieceActuelle->getInventaire().at(choix));
            pieceActuelle->inventaireEnlever(pieceActuelle->getInventaire().at(choix));
            return true;
        }
    }
    return false;
}

bool monterEscalier() {
    if (pieceActuelle->aEscalier()) {
        genererEtage();
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

void afficherAide() {
    cout << "Se déplacer : zqsd/wasd";
    cout << separateur;
    cout << "Attendre : espace";
    cout << separateur;
    cout << "Utiliser un objet : u";
    cout << separateur;
    cout << "Poser un objet : p";
    cout << separateur;
    cout << "Ramasser un objet : r";
    cout << separateur;
    cout << "Monter un escalier : e";
    cout << separateur;
    cout << "Quitter : l";
}

int main() {
    ecranTitre();
    genererEtage();

    while (1) {
        if (!combatEnnemisDansLaMemePiece()) {
            return 0;
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
                    //pieceActuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
                    tourDuJoueurFini = true;
                }
                break;

            case 'q': case 'a':
                if (joueur->getPosJ() > 0) {
                    joueur->setPosJ(joueur->getPosJ() - 1);
                    //pieceActuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
                    tourDuJoueurFini = true;
                }
                break;

            case 's':
                if (joueur->getPosI() < maxI) {
                    joueur->setPosI(joueur->getPosI() + 1);
                    //pieceActuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
                    tourDuJoueurFini = true;
                }
                break;

            case 'd':
                if (joueur->getPosJ() < maxJ) {
                    joueur->setPosJ(joueur->getPosJ() + 1);
                    //pieceActuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());
                    tourDuJoueurFini = true;
                }
                break;

            case ' ':
                tourDuJoueurFini = true;
                break;

            case 'h':
                afficherAide();
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
                cout << "Voulez-vous vraiment quitter ? Oui : o";
                cout << separateur;
                cout << "Non : Autre touche" << endl;
                cout << prompt2;
                if (getChar() == 'o') {
                    return 0;
                }
                break;

            default:
                cout << "Erreur";
                break;
            }

            cout << endl;
        }

        // Car le joueur s'est peut-être déplacé ou téléporté
        pieceActuelle = carte.at(joueur->getPosI()).at(joueur->getPosJ());

        // La santé et l'habileté du joueur se régénèrent de 1 par tour hors combat
        joueur->setSante(joueur->getSante() + 1);
        joueur->setHabilete(joueur->getHabilete() + 1);

        faireBougerLesEnnemis();

        // Apparition aléatoire d'un ennemi avec 5 % de probabilité
        if (getRandomIntBetween(1, 100) <= 5) {
            Personnage *nouvelEnnemi;

            int rand = getRandomIntBetween(1, 100);
            if (1 <= rand && rand <= 25) {
                nouvelEnnemi = new Moine{30};
            }
            else if (26 <= rand && rand <= 50) {
                nouvelEnnemi = new Guerrier{40};
            }
            else if (51 <= rand && rand <= 75) {
                nouvelEnnemi = new Sorciere{25};
            }
            else if (76 <= rand && rand <= 100) {
                nouvelEnnemi = new Amazone{30};
            }

            nouvelEnnemi->setPosI(getRandomIntBetween(0, maxI));
            nouvelEnnemi->setPosJ(getRandomIntBetween(0, maxJ));
            ennemis.push_back(nouvelEnnemi);
        }

        numeroTour++;
    }
}
