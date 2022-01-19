/*#include "Objet.hpp"
#include "Personnage.hpp"

bool Objet::isUtilisableEnCombat(Personnage *joueur) {
    return false;
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
*/

#include "Objet.hpp"

string Objet::getNom() const {
    return this->nom;
}

void Objet::setNom(const string &nom) {
    this->nom = nom;
}