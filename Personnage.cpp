#include <iostream>
#include <string>
#include "Personnage.hpp"
#include "Objet.hpp"

const string &Personnage::getNom() const {
    return nom;
}

void Personnage::setNom(const string &nom) {
    Personnage::nom = nom;
}

int Personnage::getSante() const {
    return sante;
}

void Personnage::setSante(int sante) {
    Personnage::sante = sante;
}

int Personnage::getHabilete() const {
    return habilete;
}

void Personnage::setHabilete(int habilete) {
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

Personnage::Personnage(int sante){
        this->sante = sante;
}

Personnage::Personnage(){}

int getDegatsAuPoing(){
    return 0;
}