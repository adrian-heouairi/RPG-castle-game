#include <iostream>
#include "Sorciere.hpp"
using namespace std;

Sorciere::Sorciere(int sante) : Personnage(sante) {
    setNom("Sorcière");
}

int Sorciere::getDegatsAuPoing(){
    return 5;
}