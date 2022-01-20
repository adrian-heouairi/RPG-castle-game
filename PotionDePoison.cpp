#include <iostream>
#include "PotionDePoison.hpp"
#include "Personnage.hpp"
using namespace std;

bool PotionDePoison::isUtilisableEnCombat(Personnage *joueur){
    return true;
}

string PotionDePoison::getNom() const {
    return "Potion de poison";
}

void PotionDePoison::utiliserEnCombat(Personnage *joueur, Personnage *ennemi){
    ennemi->setSante(ennemi->getSante() - 100);
}

bool PotionDePoison::isUtilisableHorsCombat(Personnage *joueur){
    return false;
}

void PotionDePoison::utiliserHorsCombat(Personnage *joueur) { }
    
bool PotionDePoison::isConsommable() {
    return true;
}