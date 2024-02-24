#include "attributCouleur.hh"

AttributCouleur::AttributCouleur(const Couleur & c)
    : Attribut::Attribut(), _couleur(c) {}

std::string AttributCouleur::valeur() const {
    return _couleur._valeur;
}
