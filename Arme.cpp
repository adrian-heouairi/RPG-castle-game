#include "Arme.hpp"

string Arme::getNom() const {
	return Objet::getNom() + " " + to_string(degats);
}

//void Arme::utiliserEnCombat(Personnage *joueur, Personnage *ennemi) {
//	ennemi->setSante(ennemi->getSante() - degats - joueur->getHabilete());
//    joueur->setHabilete(0);
//}

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