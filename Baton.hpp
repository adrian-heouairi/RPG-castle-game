#ifndef BATON_HPP
#define BATON_HPP

#include "Arme.hpp"

class Baton: public Arme{
    Baton(int degats);
    bool isUtilisableEnCombat(Personnage *joueur) override;
};


#endif
