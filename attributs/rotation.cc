#include "rotation.hh"


Rotation::Rotation(int val)
    : AttributInt::AttributInt(val) {}

std::string Rotation::type() const {
    return "rotate";
}

