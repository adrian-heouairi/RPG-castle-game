#include <iostream>
#include "Sorciere.hpp"
using namespace std;

Sorciere::Sorciere(int santeMax, int habileteMax) : Personnage(santeMax, habileteMax) {
    setNom("Sorcière");
}

int Sorciere::getDegatsAuPoing(){
    return 5;
}