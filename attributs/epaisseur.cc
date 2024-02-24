#include "epaisseur.hh"


Epaisseur::Epaisseur(int val)
    : AttributInt::AttributInt(val) {}

std::string Epaisseur::type() const {
    return "stroke-width";
}
