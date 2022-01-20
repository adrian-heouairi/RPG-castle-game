#ifndef ARME_HPP
#define ARME_HPP

#include "Objet.hpp"

class Arme: public Objet {
protected:
    int degats;
    Arme(int degats);

public:
    string getNom() const override;

    // Ces deux méthodes doivent être implémentées par les descendants :
    //virtual bool isUtilisableEnCombat(Personnage *utilisateur) = 0;
    //virtual void utiliserEnCombat(Personnage *utilisateur, Personnage *adversaire) = 0;

    bool isUtilisableHorsCombat(Personnage *joueur) override;
    void utiliserHorsCombat(Personnage *joueur) override;

    bool isConsommable() override;
};

#endif
