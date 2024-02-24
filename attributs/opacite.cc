#include "opacite.hh"
#include <iomanip>


Opacite::Opacite(int val)
    : AttributInt::AttributInt(val) {}

std::string Opacite::type() const {
    return "opacity";
}

std::string Opacite::valeur() const {
    std::ostringstream out;
    out << std::setprecision(2);
    out << _valeur / 100.0;
    return out.str();
}
