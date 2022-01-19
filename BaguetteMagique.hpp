#ifndef BAGUETTEMAGIQUE_HPP
#define BAGUETTEMAGIQUE_HPP

#include "Arme.hpp"

class BaguetteMagique: public Arme{
public:
    BaguetteMagique(int degats);
    bool isUtilisableEnCombat(Personnage *joueur) override;
};

#endif
