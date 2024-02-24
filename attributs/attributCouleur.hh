#pragma once
#include "attribut.hh"



class AttributCouleur : public Attribut {
public:
    Couleur _couleur;
    AttributCouleur(const Couleur & c);

    std::string valeur() const override;
};
