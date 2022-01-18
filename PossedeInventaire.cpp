#include "PossedeInventaire.hpp"

bool PossedeInventaire::inventaireADeLaPlace() {
    return false;
}

const vector<Objet *> &PossedeInventaire::getInventaire() const {
    return inventaire;
}

void PossedeInventaire::ajouterObjet(Objet *const &pObjet) {
    vector<Objet *> inventaire = getInventaire();
    inventaire.push_back(pObjet);
}

void PossedeInventaire::enleverObjet(Objet *const &pObjet) {
    vector<Objet *> inventaire = getInventaire();
    inventaire.erase(pObjet);
}
