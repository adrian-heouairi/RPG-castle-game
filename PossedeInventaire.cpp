#include "PossedeInventaire.hpp"

bool PossedeInventaire::inventaireADeLaPlace() {
    int sizeInventaire = getInventaire().size;
    return sizeInventaire < 4;
}

const vector<Objet *> &PossedeInventaire::getInventaire() const {
    return inventaire;
}

void PossedeInventaire::ajouterObjet(Objet *const &pObjet) {
    vector<Objet *> inventaire = getInventaire();
    if (this->inventaireADeLaPlace()){
        inventaire.push_back(pObjet);
    }
}

void PossedeInventaire::enleverObjet(Objet *const &pObjet) {
    vector<Objet *> inventaire = getInventaire();
    inventaire.erase(pObjet);
}

void inventaireEnlever(Objet *objet){

}

void inventaireAjouter(Objet *objet){
    
}