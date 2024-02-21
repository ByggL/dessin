#include "fill.hh"

Fill::Fill(const Couleur & col)
    : AttributCouleur(col) {}
Fill::Fill(std::string col)
    : AttributCouleur(col) {}

std::string Fill::type() const {
    return "fill";
}

std::string Fill::valeur() const {
    return _valeur._couleur;
}
