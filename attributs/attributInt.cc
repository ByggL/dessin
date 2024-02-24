#include "attributInt.hh"


AttributInt::AttributInt(int val)
    : Attribut(), _valeur(val) {}

std::string AttributInt::valeur() const {
    return std::to_string(_valeur);
}
