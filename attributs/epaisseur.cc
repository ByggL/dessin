#include "epaisseur.hh"


Epaisseur::Epaisseur(int val)
    : AttributInt(val) {}

std::string Epaisseur::type() const {
    return "stroke-width";
}

std::string Epaisseur::valeur() const {
    return std::to_string(_valeur);
}
