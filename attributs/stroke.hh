#pragma once
#include "attributCouleur.hh"

class Stroke : public AttributCouleur {
public:
    Stroke(const Couleur & col);

    std::string type() const override;
};
