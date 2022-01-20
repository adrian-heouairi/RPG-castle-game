#ifndef GUERRIER_HPP
#define GUERRIER_HPP

#include "Personnage.hpp"

class Guerrier: public Personnage{
public:
    Guerrier(int santeMax, int habileteMax);
    int getDegatsAuPoing() override;
};

#endif
