#pragma once
#include "attributCouleur.hh"


class Fill : public AttributCouleur {
public:
    Fill(const Couleur & col);

    std::string type() const override;
};
