#ifndef OBJET_HPP
#define OBJET_HPP

#include <iostream>
#include <string>
#include "Personnage.hpp"
using namespace std;

class Objet {
private:
    string nom;

//protected:
//    Objet();

public:
    virtual string getNom() const;
    virtual void setNom(const string &nom);

    virtual bool isUtilisableEnCombat(Personnage *utilisateur) = 0;
    virtual void utiliserEnCombat(Personnage *utilisateur, Personnage *adversaire) = 0;

    virtual bool isUtilisableHorsCombat(Personnage *utilisateur) = 0;
    virtual void utiliserHorsCombat(Personnage *utilisateur) = 0;

    virtual bool isConsommable() = 0;

    virtual ~Objet() = default;
    //virtual ~Objet() { cout << "Debug : destruction d'un objet" << endl; }
};


#endif
