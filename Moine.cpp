#include "Moine.hpp"
#include <iostream>
using namespace std;

Moine::Moine(int santeMax, int habileteMax) : Personnage(santeMax, habileteMax) {
    setNom("Moine");
}

int Moine::getDegatsAuPoing(){
    return 14;
}