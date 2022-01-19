#include "Moine.hpp"
#include <iostream>
using namespace std;

Moine::Moine(int sante) : Personnage(sante) {
    setNom("Moine");
}

int Moine::getDegatsAuPoing(){
    return 14;
}