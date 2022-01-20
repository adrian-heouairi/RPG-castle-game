#include <iostream>
#include "Baton.hpp"
#include "Moine.hpp"
using namespace std;

Baton::Baton(int degats): Arme(degats){
    setNom("Bâton");
}

bool Baton::isUtilisableEnCombat(Personnage *joueur) {
    if (dynamic_cast<Moine *>(joueur)) return true;
    else return false;
}