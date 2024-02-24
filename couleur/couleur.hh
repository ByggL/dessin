#pragma once
#include <string>
#include <memory>

// par soucis de simplicité, toutes les couleurs seront converties en hex
class Couleur {
public:
    std::string _valeur;

    Couleur() = default;
    Couleur(const std::string & valeur);
    Couleur(const Couleur & C);
    ~Couleur() = default;

};

using couleurPtr = std::shared_ptr<Couleur>;
