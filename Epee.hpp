#ifndef EPEE_HPP
#define EPEE_HPP

#include "Arme.hpp"

class Epee: public Arme{
public:
    Epee(int degats);
    bool isUtilisableEnCombat(Personnage *joueur) override;
    void utiliserEnCombat(Personnage *utilisateur, Personnage *adversaire) override;
};

#endif
