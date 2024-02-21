#include "attributCouleur.hh"

AttributCouleur::AttributCouleur(const Couleur & c)
    : Attribut(), _valeur(c._couleur) {}

AttributCouleur::AttributCouleur(std::string col)
    : Attribut(), _valeur(col) {}
