#include <iostream>
#include <string>
#include "Personnage.hpp"
using namespace std;

class Objet {
private:
    string Nom;

public:
    bool isUtilisableEnCombat(Personnage *joueur);

    const string &getNom() const;

    void setNom(const string &nom);

    void utiliserEnCombat(Personnage *joueur, Personnage *ennemi);

    bool isUtilisableHorsCombat(Personnage *joueur);

    void utiliserHorsCombat(Personnage *joueur);

    bool isConsommable();
};
