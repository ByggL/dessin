#pragma once
#include <string>
#include <memory>

// par soucis de simplicité, toutes les couleurs seront converties en hex
class Couleur {
public:
    std::string _couleur;  // au format hex

    Couleur() = default;
    Couleur(const std::string & couleur);  // au format texte, par exemple "rouge"
    Couleur(int r, int g, int b);  // au format RGB
    ~Couleur() = default;

    std::string rgb2hex(int r, int g, int b);
};

using couleurPtr = std::shared_ptr<Couleur>;
