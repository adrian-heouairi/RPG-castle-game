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
    int habilete;
    int santeMax;
    int habileteMax;
    int posI{0};
    int posJ{0};

protected:
    Personnage(int santeMax, int habileteMax);

public:
    string getNom() const;

    void setNom(const string &nom);

    int getSante() const;
    int getSanteMax() const;

    void setSante(int sante);

    int getHabilete() const;
    int getHabileteMax() const;

    void setHabilete(int habilete);

    int getPosI() const;

    void setPosI(int posI);

    int getPosJ() const;

    void setPosJ(int posJ);

    virtual int getDegatsAuPoing() = 0;

    bool inventaireADeLaPlace() override;

    virtual ~Personnage() = default;
};

#endif
