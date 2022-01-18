#include "Objet.hpp"
#include "Personnage.hpp"

bool Objet::isUtilisableEnCombat(Personnage *joueur) {
    return false;
}

const string &Objet::getNom() const {
    return Nom;
}

void Objet::setNom(const string &nom) {
    Nom = nom;
}

void Objet::utiliserEnCombat(Personnage *joueur, Personnage *ennemi) {

}

bool Objet::isUtilisableHorsCombat(Personnage *joueur) {
    return false;
}

void Objet::utiliserHorsCombat(Personnage *joueur) {

}

bool isConsommable(){
    return false;
}
