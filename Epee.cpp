#include <iostream>
#include "Epee.hpp"
#include "Guerrier.hpp"
#include "Amazone.hpp"
using namespace std;

Epee::Epee(int degats): Arme(degats){
    setNom("Epée");
}

bool Epee::isUtilisableEnCombat(Personnage *joueur) {
    if (dynamic_cast<Guerrier *>(joueur)) return true;
    else return false;
}

void Epee::utiliserEnCombat(Personnage *utilisateur, Personnage *adversaire) {
    int degatsInfliges = degats;

    if (dynamic_cast<Amazone *>(adversaire)) degatsInfliges *= 1.2;
    
    adversaire->setSante(adversaire->getSante() - degatsInfliges - utilisateur->getHabilete());
    utilisateur->setHabilete(0);
}
