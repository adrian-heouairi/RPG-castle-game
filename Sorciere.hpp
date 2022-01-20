#ifndef SORCIERE_HPP
#define SORCIERE_HPP

#include "Personnage.hpp"

class Sorciere: public Personnage{
public:
    Sorciere(int santeMax, int habileteMax);
    int getDegatsAuPoing() override;
};

#endif
