#ifndef MOINE_HPP
#define MOINE_HPP

#include "Personnage.hpp"

class Moine: public Personnage{
public:
    Moine(int santeMax, int habileteMax);
    int getDegatsAuPoing() override;
};

#endif
