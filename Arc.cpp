#include <iostream>
#include "Arc.hpp"
using namespace std;

Arc::Arc(int degats) : Arme(degats) {}

bool Arc::isUtilisableEnCombat(Personnage *joueur) {
    if (dynamic_cast<Guerrier *>(joueur)) return true;
    else return false;
}