#include <iostream>
#include <string>
using namespace std;

class Personnage{
private:
    string nom;
    int sante;
    int habilete;
    int posI;
    int posJ;
//    Objets sac[4];

public:
    const string &getNom() const {
        return nom;
    }

    void setNom(const string &nom) {
        Personnage::nom = nom;
    }

    int getSante() const {
        return sante;
    }

    void setSante(int sante) {
        Personnage::sante = sante;
    }

    int getHabilete() const {
        return habilete;
    }

    void setHabilete(int habilete) {
        Personnage::habilete = habilete;
    }

    int getPosI() const {
        return posI;
    }

    void setPosI(int posI) {
        Personnage::posI = posI;
    }

    int getPosJ() const {
        return posJ;
    }

    void setPosJ(int posJ) {
        Personnage::posJ = posJ;
    }
};

class Guerrier: public Personnage{

};

class Moines: public Personnage{

};

class Sorciers: public Personnage{

};

class Amazones: public Personnage{

};