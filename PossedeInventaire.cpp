#include "PossedeInventaire.hpp"

bool PossedeInventaire::inventaireADeLaPlace() {
    int sizeInventaire = getInventaire().size;
    return sizeInventaire < 4;
}

const vector<Objet *> &PossedeInventaire::getInventaire() const {
    return inventaire;
}

void inventaireEnlever(Objet *objet){

}

void inventaireAjouter(Objet *objet){
    
}