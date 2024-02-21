#pragma once
#include "attributCouleur.hh"

class Stroke : public AttributCouleur {
public:
    Stroke(const Couleur & col);
    Stroke(std::string col);

    std::string type() const override;
    std::string valeur() const override;
};
