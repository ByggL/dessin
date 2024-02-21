#pragma once
#include "attributCouleur.hh"


class Fill : public AttributCouleur {
public:
    Fill(const Couleur & col);
    Fill(std::string col);

    std::string type() const override;
    std::string valeur() const override;
};
