#include <iostream>
#include <string>
using namespace std;

class Objet {
private:
    string Nom;

public:
    bool isUtilisableEnCombat();

    const string &getNom() const;

    void setNom(const string &nom);

    void utiliserEnCombat();

    bool isUtilisable();

    void utiliser();
};
