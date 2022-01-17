#include <iostream>
#include <string>
using namespace std;

#ifndef PROJET_OBJET_HPP
#define PROJET_OBJET_HPP


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


#endif //PROJET_OBJET_HPP
