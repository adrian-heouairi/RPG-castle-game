#ifndef EPEE_HPP
#define EPEE_HPP

#include "Arme.hpp"

class Epee: public Arme{
    Epee(int degats);
    bool isUtilisableEnCombat(Personnage *joueur) override;
};

#endif
