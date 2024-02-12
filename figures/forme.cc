#include "forme.hh"
#include <stdexcept>
#include <iostream>
#include <sstream>


Forme::Forme(std::vector<std::string> attributs, std::vector<std::string> valeurs) {
    if(!(attributs.size() == valeurs.size())) throw std::invalid_argument("Nombre d'attributs et de valeurs différent");
    for (unsigned int i = 0; i < attributs.size(); i++) {
        _attributs[attributs[i]] = valeurs[i];
    }
}

Forme::Forme() : _attributs({}) {}

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