#include "Objet.hpp"

bool Objet::isUtilisableEnCombat() {
    return false;
}

const string &Objet::getNom() const {
    return Nom;
}

void Objet::setNom(const string &nom) {
    Nom = nom;
}

void Objet::utiliserEnCombat() {

}

bool Objet::isUtilisable() {
    return false;
}

void Objet::utiliser() {

}
