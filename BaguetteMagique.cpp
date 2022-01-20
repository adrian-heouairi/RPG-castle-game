#include <iostream>
#include "BaguetteMagique.hpp"
#include "Sorciere.hpp"
using namespace std;

BaguetteMagique::BaguetteMagique(int degats): Arme(degats){
    setNom("Baguette magique");
}

bool BaguetteMagique::isUtilisableEnCombat(Personnage *joueur) {
    if (dynamic_cast<Sorciere *>(joueur)) return true;
    else return false;
}