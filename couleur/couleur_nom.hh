#pragma once
#include "couleur.hh"

// au format texte, par exemple "rouge"
class Couleur_nom : public Couleur {
public:
    Couleur_nom() = default;
    Couleur_nom(const std::string & couleur);
    ~Couleur_nom() =default;

};
