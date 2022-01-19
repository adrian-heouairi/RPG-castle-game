#ifndef POSSEDEINVENTAIRE_HPP
#define POSSEDEINVENTAIRE_HPP

#include <iostream>
#include <vector>
//#include "Objet.hpp"
using namespace std;

class Objet;

class PossedeInventaire {
private:
    vector<Objet *> inventaire;
public:
    virtual bool inventaireADeLaPlace() = 0;

    const vector<Objet *> &getInventaire() const;

    void inventaireEnlever(Objet *objet);

    void inventaireAjouter(Objet *objet);

    virtual ~PossedeInventaire();
};

#endif
