#ifndef POTIONDESOIN_HPP
#define POTIONDESOIN_HPP
#include <iostream>
#include "Objet.hpp"
using namespace std;

class PotionDeSoin: public Objet{
    //int soin;
public:
    //PotionDeSoin();

    string getNom() const override;

    bool isUtilisableEnCombat(Personnage *joueur) override;
    void utiliserEnCombat(Personnage *joueur, Personnage *ennemi) override;

    bool isUtilisableHorsCombat(Personnage *joueur) override;
    void utiliserHorsCombat(Personnage *joueur) override;
    
    bool isConsommable() override;
};

#endif
