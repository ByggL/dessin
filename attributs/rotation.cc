#include "rotation.hh"


Rotation::Rotation(int val)
    : AttributInt(val) {}

std::string Rotation::type() const {
    return "rotate";
}

std::string Rotation::valeur() const {
    return std::to_string(_valeur);
}
