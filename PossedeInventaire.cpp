#include "PossedeInventaire.hpp"

bool PossedeInventaire::inventaireADeLaPlace() {
    return false;
}

const vector<Objet *> &PossedeInventaire::getInventaire() const {
    return inventaire;
}

void PossedeInventaire::ajouterObjet(Objet *const &pObjet) {

}

void PossedeInventaire::enleverObjet(Objet *const &pObjet) {

}
