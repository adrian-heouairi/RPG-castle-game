#include <iostream>
#include "PotionDeSoin.hpp"
using namespace std;

//PotionDeSoin::PotionDeSoin(){
//    this->soin = 100;
//}

bool PotionDeSoin::isUtilisableEnCombat(Personnage *joueur){
    return true;
}

string PotionDeSoin::getNom() const {
    return "Potion de soin";
}

void PotionDeSoin::utiliserEnCombat(Personnage *joueur, Personnage *ennemi){
    utiliserHorsCombat(joueur);
}

bool PotionDeSoin::isUtilisableHorsCombat(Personnage *joueur){
    return true;
}

void PotionDeSoin::utiliserHorsCombat(Personnage *joueur){
    joueur->setSante(joueur->getSante() + 50);
}
    
bool PotionDeSoin::isConsommable(){
    return true;
}