#include "Guerrier.hpp"

Guerrier::Guerrier(int sante) : Personnage(sante) {
    setNom("Guerrier");
}

int Guerrier::getDegatsAuPoing(){
    return 10;
}