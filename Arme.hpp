#ifndef ARME_HPP
#define ARME_HPP

#include "Objet.hpp"

class Arme: public Objet {
private:
    int degats;

protected:
    Arme(int degats);

public:
    string getNom() const override;

    //virtual bool isUtilisableEnCombat(Personnage *joueur) = 0;
    void utiliserEnCombat(Personnage *joueur, Personnage *ennemi) override;

    bool isUtilisableHorsCombat(Personnage *joueur) override;
    void utiliserHorsCombat(Personnage *joueur) override;

    bool isConsommable() override;
};

#endif
