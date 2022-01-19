#ifndef ARC_HPP
#define ARC_HPP

#include "Arme.hpp"

class Arc: public Arme{
    Arc(int degats);
    bool isUtilisableEnCombat(Personnage *joueur) override;
};

#endif
