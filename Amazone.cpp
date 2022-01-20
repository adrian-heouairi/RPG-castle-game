#include "Amazone.hpp"

Amazone::Amazone(int santeMax, int habileteMax) : Personnage(santeMax, habileteMax) {
    setNom("Amazone");
}

int Amazone::getDegatsAuPoing(){
    return 7;
}