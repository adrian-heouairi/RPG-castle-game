#include <iostream>
#include "Baton.hpp"
#include "Moine.hpp"
#include "Sorciere.hpp"
using namespace std;

Baton::Baton(int degats): Arme(degats){
    setNom("Bâton");
}

bool Baton::isUtilisableEnCombat(Personnage *joueur) {
    if (dynamic_cast<Moine *>(joueur)) return true;
    else return false;
}

void Baton::utiliserEnCombat(Personnage *utilisateur, Personnage *adversaire) {
    int degatsInfliges = degats;

    if (dynamic_cast<Sorciere *>(adversaire)) degatsInfliges *= 1.2;
    
    adversaire->setSante(adversaire->getSante() - degatsInfliges - utilisateur->getHabilete());
    utilisateur->setHabilete(0);
}
