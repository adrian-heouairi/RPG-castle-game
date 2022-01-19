#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>
#include <string>
#include <vector>
#include "PossedeInventaire.hpp"
#include "Objet.hpp"

class Piece: public PossedeInventaire {
private:
    bool escalier = false;

public:
    bool aEscalier();

    void setEscalier(bool escalier);

    bool inventaireADeLaPlace() override;

    virtual ~Piece() = default;
};

#endif
