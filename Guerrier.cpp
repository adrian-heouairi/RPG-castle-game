#include "Guerrier.hpp"

Guerrier::Guerrier(int santeMax, int habileteMax) : Personnage(santeMax, habileteMax) {
    setNom("Guerrier");
}

int Guerrier::getDegatsAuPoing(){
    return 10;
}