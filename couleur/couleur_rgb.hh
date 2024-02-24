#pragma once
#include "couleur.hh"

// au format RGB
class Couleur_rgb : public Couleur {
public:
    Couleur_rgb() = default;
    Couleur_rgb(int r, int g, int b);
    ~Couleur_rgb() = default;

    std::string rgb2hex(int r, int g, int b);
};

