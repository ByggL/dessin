#include "attributCouleur.hh"

AttributCouleur::AttributCouleur(const Couleur & c)
    : Attribut(), valeur(c._couleur) {}

AttributCouleur::AttributCouleur(std::string col)
    : Attribut(), valeur(col) {}