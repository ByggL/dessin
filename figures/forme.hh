#pragma once
#include <memory>
#include "couleur.hh"
#include "contexte.hh"
#include <string>
#include <vector>
#include <map>

using mapStrStr = std::map<std::string, std::string>;

class Forme {
public:
    // Proposition Samuel
    // mapStrStr _attributs;
    // Forme(std::vector<std::string> attributs, std::vector<std::string> valeurs);

    // Proposition Ruben
    struct Attribut {
        std::unique_ptr<Couleur> couleur;
        std::unique_ptr<Couleur> remplissage;
        int rotation;
        float opacite;
        int epaisseur;
    };

    Attribut attributs;

    Forme();
    virtual ~Forme() = default;

    // Ne Compile pas
    // TODO : Une fonction virtual doit etre définie.
    // virtual int centreX();
    // virtual int centreY();

    void addAttribut(std::string attribut, std::string valeur);
    void addAttribut(std::string attribut, int valeur);
    std::string toSVG();
};

using formePtr = std::shared_ptr<Forme>;