#ifndef OBJET_HPP
#define OBJET_HPP

#include <iostream>
#include <string>
#include "Personnage.hpp"
using namespace std;

class Objet {
private:
    string nom;

public:
    virtual bool isUtilisableEnCombat(Personnage *joueur) = 0;

    virtual string getNom() const;

    virtual void setNom(const string &nom);

    virtual void utiliserEnCombat(Personnage *joueur, Personnage *ennemi) = 0;

    virtual bool isUtilisableHorsCombat(Personnage *joueur) = 0;

    virtual void utiliserHorsCombat(Personnage *joueur) = 0;

    virtual bool isConsommable() = 0;
};


#endif
