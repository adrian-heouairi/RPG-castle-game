#include "CleDeTeleportation.hpp"
#include "Personnage.hpp"

extern int maxI;
extern int maxJ;
extern int getRandomIntBetween(int a, int b);

//CleDeTeleportation::CleDeTeleportation() {
//    setNom("Clé de téléportation");
//}

string CleDeTeleportation::getNom() const {
    return "Clé de téléportation";
}

bool CleDeTeleportation::isUtilisableEnCombat(Personnage *joueur) {
	return true;
}

void CleDeTeleportation::utiliserEnCombat(Personnage *joueur, Personnage *ennemi) {
	utiliserHorsCombat(joueur);
}

bool CleDeTeleportation::isUtilisableHorsCombat(Personnage *joueur) {
	return true;
}

void CleDeTeleportation::utiliserHorsCombat(Personnage *joueur) {
	joueur->setPosI(getRandomIntBetween(0, maxI));
    joueur->setPosJ(getRandomIntBetween(0, maxJ));
}

bool CleDeTeleportation::isConsommable() {
	return true;
}
