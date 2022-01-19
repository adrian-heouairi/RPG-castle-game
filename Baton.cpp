#include <iostream>
#include "Baton.hpp"
using namespace std;

Baton::Baton(int degats): Arme(degats){}

bool Baton::isUtilisableEnCombat(Personnage *joueur) {
    if (dynamic_cast<Moine *>(joueur)) return true;
    else return false;
}