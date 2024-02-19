#pragma once
#include <string>

// par soucis de simplicité, toutes les couleurs seront converties en hex
class Couleur {
public:
    std::string _couleur;  // au format hex

    Couleur() = default;
    Couleur(std::string couleur);  // au format texte, par exemple "rouge"
    Couleur(int r, int g, int b);  // au format RGB
    ~Couleur() = default;

    std::string rgb2hex(unsigned int r, unsigned int g, unsigned int b);
};

using couleurPTR = std::shared_ptr<Couleur>;
