#pragma once
#include <memory>
#include "couleur.hh"
#include "contexte.hh"
#include <string>
#include <vector>
#include <map>


class Forme {
public:
    Struct Attribut {
        Couleur couleur;
        Couleur remplissage;
        std::string rotation;
        std::string opacite;
        int epaisseur;
    }

    Attribut attributs;

    Forme();
    virtual ~Forme() = default;
    // virtual int centreX();
    // virtual int centreY();

    void addAttribut(std::string attribut, std::string valeur);
    std::string toSVG();
};

using formePtr = std::shared_ptr<Forme>;
