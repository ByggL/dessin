#pragma once
#include <memory>
#include "couleur.hh"
#include "contexte.hh"
#include <string>
#include <vector>
#include <map>


class Forme {
public:
    // Proposition Samuel
    std::map<std::string, std::string> _attributs;
    Forme(std::vector<std::string> attributs, std::vector<std::string> valeurs);

    // Proposition Ruben
    // Struct Attribut {
    //     std::unique_ptr<Couleur> couleur;
    //     std::unique_ptr<Couleur> remplissage;
    //     int rotation;
    //     int opacite;
    //     int epaisseur;
    // }
    Forme();
    virtual ~Forme() = default;

    // Ne Compile pas
    // TODO : Une fonction virtual doit etre définie.
    // virtual int centreX();
    // virtual int centreY();

    void addAttribut(std::string attribut, std::string valeur);
    std::string toSVG();
};

using formePtr = std::shared_ptr<Forme>;
