#ifndef CLEDETELEPORTATION_HPP
#define CLEDETELEPORTATION_HPP

#include "Objet.hpp"

class CleDeTeleportation: public Objet{
public:
    CleDeTeleportation();

    bool isUtilisableEnCombat(Personnage *joueur) override;

    void utiliserEnCombat(Personnage *joueur, Personnage *ennemi) override;

    bool isUtilisableHorsCombat(Personnage *joueur) override;

    void utiliserHorsCombat(Personnage *joueur) override;

    bool isConsommable() override;
};

#endif
