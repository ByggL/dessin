#include "attribut.hh"
#include "couleur.hh"


class AttributCouleur : public Attribut {
public: 
    Couleur valeur;
    AttributCouleur(const Couleur & c);
    AttributCouleur(std::string col);
};