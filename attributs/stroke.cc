#include "stroke.hh"


Stroke::Stroke(const Couleur & col)
    : AttributCouleur(col) {}
Stroke::Stroke(std::string col)
    : AttributCouleur(col) {}

std::string Stroke::type() const {
    return "stroke";
}

std::string Stroke::valeur() const {
    return _valeur._couleur;
}
