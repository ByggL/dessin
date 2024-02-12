
#pragma once
#include <memory>
#include "couleur.hh"
#include "contexte.hh"
#include <string>
#include <vector>
#include <map>


class Forme {
protected:
    std::map<std::string, std::string> _attributs;
public:
    // Couleur couleur;
    // Couleur remplissage;
    // std::string rotation;
    // std::string opacite;
    // int epaisseur;
    Forme(std::vector<std::string> attributs, std::vector<std::string> valeurs);
    Forme();
    virtual ~Forme() = default;

    void addAttribut(std::string attribut, std::string valeur);
    std::string toSVG();
};

using formePtr = std::shared_ptr<Forme>;
