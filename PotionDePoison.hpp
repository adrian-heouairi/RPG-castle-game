#ifndef POTIONDEPOISON_HPP
#define POTIONDEPOISON_HPP

#include "Objet.hpp"

class PotionDePoison: public Objet{
private:
    int sante;
public:
    PotionDePoison();

    bool isUtilisableEnCombat(Personnage *joueur);

    string getNom();

    void utiliserEnCombat(Personnage *joueur, Personnage *ennemi);

    bool isUtilisableHorsCombat(Personnage *joueur);

    void utiliserHorsCombat(Personnage *joueur);
    
    bool isConsommable();
};

#endif
