#include <iostream>
#include "Epee.hpp"
#include "Guerrier.hpp"
using namespace std;

Epee::Epee(int degats): Arme(degats){
    setNom("Epée");
}

bool Epee::isUtilisableEnCombat(Personnage *joueur) {
    if (dynamic_cast<Guerrier *>(joueur)) return true;
    else return false;
}