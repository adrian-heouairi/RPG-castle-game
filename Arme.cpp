#include "Arme.hpp"

string Arme::getNom() const {
	return Objet::getNom() + " " + to_string(degats);
}

bool Arme::isUtilisableHorsCombat(Personnage *joueur) {
	return false;
}

void Arme::utiliserHorsCombat(Personnage *joueur) { }

bool Arme::isConsommable() {
	return false;
}

Arme::Arme(int degats) {
    this->degats = degats;
}