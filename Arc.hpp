#ifndef ARC_HPP
#define ARC_HPP

#include "Arme.hpp"

class Arc: public Arme{
public:
    Arc(int degats);
    bool isUtilisableEnCombat(Personnage *joueur) override;
};

#endif
