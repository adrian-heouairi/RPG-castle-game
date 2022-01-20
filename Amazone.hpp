#ifndef AMAZONE_HPP
#define AMAZONE_HPP

#include "Personnage.hpp"

class Amazone: public Personnage{
public:
    Amazone(int santeMax, int habileteMax);
    
    int getDegatsAuPoing() override;
};

#endif
