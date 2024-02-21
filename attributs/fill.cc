#include "fill.hh"

Fill::Fill(const Couleur & col)
    : AttributCouleur(col) {}
Fill::Fill(std::string col)
    : AttributCouleur(col) {}

std::string Fill::toSVG() {
    std::ostringstream out;

    out << " fill=\"" << valeur._couleur << "\"";

    return out.str();
}