#include "opacite.hh"


Opacite::Opacite(int val)
    : AttributInt(val) {}

std::string Opacite::type() const {
    return "opacity";
}

std::string Opacite::valeur() const {
    return std::to_string(_valeur);
}
