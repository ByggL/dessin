#include "stroke.hh"


Stroke::Stroke(const Couleur & col)
    : AttributCouleur::AttributCouleur(col) {}

std::string Stroke::type() const {
    return "stroke";
}
