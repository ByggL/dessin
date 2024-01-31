#include "forme.hh"
#include <stdexcept>


Forme::Forme(std::vector<std::string> attributs, std::vector<std::string> valeurs) {
    if(!(attributs.size() == valeurs.size())) throw std::invalid_argument("Nombre d'attributs et de valeurs différent");
    for (unsigned int i = 0; i < attributs.size(); i++) {
        _attributs[attributs[i]] = valeurs[i];
    }
}