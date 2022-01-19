#ifndef POTIONDESOIN_HPP
#define POTIONDESOIN_HPP
#include <iostream>
#include "Objet.hpp"
using namespace std;

class PotionDeSoin: public Objet{
    int soin;
public:
    PotionDeSoin();

    bool isUtilisableEnCombat(Personnage *joueur);

    string getNom();

    void utiliserEnCombat(Personnage *joueur, Personnage *ennemi);

    bool isUtilisableHorsCombat(Personnage *joueur);

    void utiliserHorsCombat(Personnage *joueur);
    
    bool isConsommable();
};

#endif
