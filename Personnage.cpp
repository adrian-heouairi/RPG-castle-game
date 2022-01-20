#include <iostream>
#include <string>
#include "Personnage.hpp"

string Personnage::getNom() const {
    return nom;
}

void Personnage::setNom(const string &nom) {
    Personnage::nom = nom;
}

int Personnage::getSante() const {
    return sante;
}

int Personnage::getSanteMax() const {
    return santeMax;
}

void Personnage::setSante(int sante) {
    if (sante < 0) sante = 0;
    if (sante > santeMax) sante = santeMax;

    Personnage::sante = sante;
}

int Personnage::getHabilete() const {
    return habilete;
}

int Personnage::getHabileteMax() const {
    return habileteMax;
}

void Personnage::setHabilete(int habilete) {
    if (habilete < 0) habilete = 0;
    if (habilete > habileteMax) habilete = habileteMax;

    Personnage::habilete = habilete;
}

int Personnage::getPosI() const {
    return posI;
}

void Personnage::setPosI(int posI) {
    Personnage::posI = posI;
}

int Personnage::getPosJ() const {
    return posJ;
}

void Personnage::setPosJ(int posJ) {
    Personnage::posJ = posJ;
}

Personnage::Personnage(int santeMax, int habileteMax) {
    this->sante = santeMax;
    this->santeMax = santeMax;
    this->habilete = habileteMax;
    this->habileteMax = habileteMax;
}

bool Personnage::inventaireADeLaPlace() {
    return this->getInventaire().size() < 6;
}
