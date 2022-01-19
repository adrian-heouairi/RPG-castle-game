#ifndef SORCIERE_HPP
#define SORCIERE_HPP

#include "Personnage.hpp"

class Sorciere: public Personnage{
public:
    Sorciere(int sante);
    int getDegatsAuPoing();
};

#endif
