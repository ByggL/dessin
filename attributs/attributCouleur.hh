#pragma once
#include "attribut.hh"
#include "couleur.hh"


class AttributCouleur : public Attribut {
public:
    Couleur _valeur;
    AttributCouleur(const Couleur & c);
    AttributCouleur(std::string col);
};
