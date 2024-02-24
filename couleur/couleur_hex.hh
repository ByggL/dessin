#pragma once
#include "couleur.hh"

class Couleur_hex : public Couleur {
public:
    Couleur_hex() = default;
    Couleur_hex(const std::string & couleur);
    ~Couleur_hex() =default;

};
