#include "Objet.hpp"

string Objet::getNom() const {
    return this->nom;
}

void Objet::setNom(const string &nom) {
    this->nom = nom;
}