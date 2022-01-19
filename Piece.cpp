#include "Piece.hpp"

bool Piece::aEscalier() {
    return this->escalier;
}

void Piece::setEscalier(bool escalier) {
    this->escalier = escalier;
}

bool Piece::inventaireADeLaPlace() {
    return true;
}
