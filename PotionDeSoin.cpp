#include <iostream>
#include "PotionDeSoin.hpp"
using namespace std;

PotionDeSoin::PotionDeSoin(){
    this->soin = 100;
}

bool isUtilisableEnCombat(Personnage *joueur){
    return true;
}

string getNom(){
    return "Potion De Soin";
}

void utiliserEnCombat(Personnage *joueur, Personnage *ennemi){
    ennemi->setSante(joueur->getSante() - 100);
}

bool isUtilisableHorsCombat(Personnage *joueur){
    return true;
}

void utiliserHorsCombat(Personnage *joueur){
    joueur->setSante(joueur->getSante() + 100);
}
    
bool isConsommable(){
    return true;
}