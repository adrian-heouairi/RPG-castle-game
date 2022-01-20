#include <iostream>
#include "BaguetteMagique.hpp"
#include "Sorciere.hpp"
#include "Guerrier.hpp"
using namespace std;

BaguetteMagique::BaguetteMagique(int degats): Arme(degats){
    setNom("Baguette magique");
}

bool BaguetteMagique::isUtilisableEnCombat(Personnage *joueur) {
    if (dynamic_cast<Sorciere *>(joueur)) return true;
    else return false;
}

void BaguetteMagique::utiliserEnCombat(Personnage *utilisateur, Personnage *adversaire) {
    int degatsInfliges = degats;

    if (dynamic_cast<Guerrier *>(adversaire)) degatsInfliges *= 1.2;
    
    adversaire->setSante(adversaire->getSante() - degatsInfliges - utilisateur->getHabilete());
    utilisateur->setHabilete(0);
}
