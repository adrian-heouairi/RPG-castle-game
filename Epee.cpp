#include <iostream>
#include "Epee.hpp"
using namespace std;

Epee::Epee(int degats): Arme(degats){}

bool Epee::isUtilisableEnCombat(Personnage *joueur) {
    if (dynamic_cast<Guerrier *>(joueur)) return true;
    else return false;
}