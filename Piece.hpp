#ifndef PROJET_PIECE_HPP
#define PROJET_PIECE_HPP
#include <iostream>
#include <string>
#include <vector>
#include "PossedeInventaire.hpp"
#include "Objet.hpp"

class Piece: PossedeInventaire {
    vector<Objet*> Objets;

public:
    const vector<struct Objet *> *const getObjets() const;

    bool aEscalier();

    void ajouterObjet(Objet *const &pObjet);

    void enleverObjet(Objet *const &pObjet);
};


#endif //PROJET_PIECE_HPP
