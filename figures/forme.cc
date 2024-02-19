#include "forme.hh"
#include <stdexcept>
#include <iostream>
#include <sstream>



Forme::Forme() : attributs() {}

void Forme::addAttribut(std::string attribut, std::string valeur) {
    _attributs[attribut] = valeur;
}

std::string Forme::toSVG() {  // retourne une string de type « attribut1="valeur1" attribut2="valeur2" »
    std::ostringstream out;

    for (auto it = _attributs.begin(); it != _attributs.end(); it++) {
        out << it->first << "=\"" << it->second << "\" ";
    }

    std::string s = out.str();
    return s;
}
