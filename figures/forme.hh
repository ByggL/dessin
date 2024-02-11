#pragma once
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <vector>
#include "couleur.hh"

class Forme {
public:
    // Couleur couleur;
    // Couleur remplissage;
    // std::string rotation;
    // std::string opacite;
    // int epaisseur;

    Forme() =default;
    // Forme(const Couleur & cou, const Couleur & rem, const std::string & rot, const std::string & opa, int epa);
    virtual ~Forme() = default;

};

using formePtr = std::shared_ptr<Forme>;
