#include "stroke.hh"


Stroke::Stroke(const Couleur & col)
    : AttributCouleur(col) {}
Stroke::Stroke(std::string col)
    : AttributCouleur(col) {}
