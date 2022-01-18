#ifndef PROJET_PIECE_HPP
#define PROJET_PIECE_HPP
#include <iostream>
#include <string>
#include <vector>
#include "PossedeInventaire.hpp"
#include "Objet.hpp"

class Piece: public PossedeInventaire {
private:
    vector<Objet*> Objets;
    bool escalier;

public:
    const vector<Objet *> getObjets() const;

    bool aEscalier();

};


#endif //PROJET_PIECE_HPP
