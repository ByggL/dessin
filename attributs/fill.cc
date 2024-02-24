#include "fill.hh"

Fill::Fill(const Couleur & col)
    : AttributCouleur::AttributCouleur(col) {}

std::string Fill::type() const {
    return "fill";
}
