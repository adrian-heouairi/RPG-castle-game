#include <iostream>
#include <string>
#include <vector>
#include "Objet.hpp"
#include "PossedeInventaire.hpp"

using namespace std;

#ifndef PROJET_PERSONNAGE_HPP
#define PROJET_PERSONNAGE_HPP


class Personnage: public PossedeInventaire {
private:
    string nom;
    int sante;
    int habilete{};
    int posI{};
    int posJ{};

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
};


#endif //PROJET_PERSONNAGE_HPP
