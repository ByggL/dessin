#pragma once
#include <string>
#include <memory>

// par soucis de simplicité, toutes les couleurs seront converties en hex
class Couleur {
public:
    std::string _couleur;  // au format hex

    Couleur() = default;
    Couleur(std::string couleur);  // au format texte, par exemple "rouge"
    Couleur(int r, int g, int b);  // au format RGB
    Couleur(const Couleur & col);
    ~Couleur() = default;

    std::string rgb2hex(unsigned int r, unsigned int g, unsigned int b);
    std::string stringColorToHex(std::string couleur);

    Couleur & operator=(std::string const & col);
    bool operator==(std::string const & col);
    bool operator!=(std::string const & col);
};

using couleurPtr = std::shared_ptr<Couleur>;
