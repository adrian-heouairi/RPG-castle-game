#ifndef POTIONDEPOISON_HPP
#define POTIONDEPOISON_HPP

#include "Objet.hpp"

class PotionDePoison: public Objet{
private:
    int sante;
public:
    PotionDePoison();

    bool isUtilisableEnCombat(Personnage *joueur) override;

    string getNom() const override;

    void utiliserEnCombat(Personnage *joueur, Personnage *ennemi) override;

    bool isUtilisableHorsCombat(Personnage *joueur) override;

    void utiliserHorsCombat(Personnage *joueur) override;
    
    bool isConsommable() override;
};

#endif
