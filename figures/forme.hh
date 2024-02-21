#pragma once
#include <memory>
#include "couleur.hh"
#include "contexte.hh"
#include <string>
#include <vector>
#include <map>


class Forme {
public:
    //TODO : Faire une class attribut -> attribut_couleur et attribut_int
    struct Attribut {
        std::shared_ptr<Couleur> couleur;
        std::shared_ptr<Couleur> remplissage;
        int rotation;
        int opacite;
        int epaisseur;
    };

    Attribut _attributs;
    Forme();
    virtual ~Forme() = default;

    // Ne Compile pas
    // TODO : Une fonction virtual doit etre définie.
    // virtual int centreX();
    // virtual int centreY();

    std::string toSVG();
};

using Attribut = Forme::Attribut;
using formePtr = std::shared_ptr<Forme>;


