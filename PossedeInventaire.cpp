#include "PossedeInventaire.hpp"

const vector<Objet *> &PossedeInventaire::getInventaire() const {
    return inventaire;
}

void PossedeInventaire::inventaireEnlever(Objet *objet) {
    for (int i = 0; i < (int)inventaire.size(); i++) {
        if (inventaire.at(i) == objet) {
            inventaire.erase(inventaire.begin() + i);
            break;
        }
    }
}

void PossedeInventaire::inventaireAjouter(Objet *objet) {
    inventaire.push_back(objet);
}

PossedeInventaire::~PossedeInventaire() {
    for (Objet *o : inventaire) {
        delete o;
    }
}