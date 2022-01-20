#include <iostream>
#include "Arc.hpp"
#include "Amazone.hpp"
#include "Moine.hpp"
using namespace std;

Arc::Arc(int degats) : Arme(degats) {
    setNom("Arc");
}

bool Arc::isUtilisableEnCombat(Personnage *joueur) {
    if (dynamic_cast<Amazone *>(joueur)) return true;
    else return false;
}

void Arc::utiliserEnCombat(Personnage *utilisateur, Personnage *adversaire) {
    int degatsInfliges = degats;

    if (dynamic_cast<Moine *>(adversaire)) degatsInfliges *= 1.2;
    
    adversaire->setSante(adversaire->getSante() - degatsInfliges - utilisateur->getHabilete());
    utilisateur->setHabilete(0);
}
