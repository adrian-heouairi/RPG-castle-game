#ifndef AMAZONE_HPP
#define AMAZONE_HPP

#include "Personnage.hpp"

class Amazone: public Personnage{
public:
    Amazone(int sante);
    
    int getDegatsAuPoing() override;
};

#endif
