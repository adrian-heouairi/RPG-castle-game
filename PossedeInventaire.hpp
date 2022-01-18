#include <iostream>
#include <vector>
#include "Objet.hpp"
using namespace std;

class PossedeInventaire {
private:
    vector<Objet*> inventaire;
public:
    bool inventaireADeLaPlace();

    const vector<Objet *> &getInventaire() const;

    void inventaireEnlever(Objet *objet);

    void inventaireAjouter(Objet *objet);
};