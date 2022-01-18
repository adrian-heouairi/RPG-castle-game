#ifndef PROJET_POSSEDEINVENTAIRE_HPP
#define PROJET_POSSEDEINVENTAIRE_HPP

#include <iostream>
#include <vector>
#include "Objet.hpp"
using namespace std;

class PossedeInventaire {
public:
    vector<Objet*> inventaire;

    bool inventaireADeLaPlace();

    void ajouterObjet(Objet *const &pObjet);

    void enleverObjet(Objet *const &pObjet);

    const vector<Objet *> &getInventaire() const;
};


#endif //PROJET_POSSEDEINVENTAIRE_HPP
