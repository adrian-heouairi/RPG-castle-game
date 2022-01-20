#include <iostream>
#include "Arc.hpp"
#include "Guerrier.hpp"
using namespace std;

Arc::Arc(int degats) : Arme(degats) {
    setNom("Arc");
}

bool Arc::isUtilisableEnCombat(Personnage *joueur) {
    if (dynamic_cast<Guerrier *>(joueur)) return true;
    else return false;
}