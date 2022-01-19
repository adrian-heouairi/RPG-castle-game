#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <iostream>
#include <string>
#include <vector>
//#include "Objet.hpp"
#include "PossedeInventaire.hpp"

using namespace std;

class Personnage : public PossedeInventaire {
private:
    string nom;
    int sante;
    int habilete{10};
    int posI{0};
    int posJ{0};

public:
    const string &getNom() const;

    void setNom(const string &nom);

    int getSante() const;

    void setSante(int sante);

    int getHabilete() const;

    void setHabilete(int habilete);

    int getPosI() const;

    void setPosI(int posI);

    int getPosJ() const;

    void setPosJ(int posJ);

    //Personnage(int sante);

    virtual int getDegatsAuPoing() = 0;

    virtual bool inventaireADeLaPlace();
};

#endif
