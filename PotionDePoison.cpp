#include <iostream>
#include "PotionDePoison.hpp"
using namespace std;

PotionDePoison::PotionDePoison(){
    this->sante = 100;
}

bool isUtilisableEnCombat(Personnage *joueur){
    return true;
}

string getNom(){
    return "Potion De Poison";
}

void utiliserEnCombat(Personnage *joueur, Personnage *ennemi){
    joueur->setSante(joueur->getSante() - 100);
}

bool isUtilisableHorsCombat(Personnage *joueur){
    return true;
}

void utiliserHorsCombat(Personnage *joueur){
    joueur->setSante(joueur->getSante() - 100);
}
    
bool isConsommable(){
    return false;
}