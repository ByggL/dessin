#pragma once
#include <memory>
#include "couleur.hh"
#include "contexte.hh"
#include <string>
#include <vector>
#include <map>


class Forme {
public:
    // Proposition Samuel pour les attributs, un map.
    std::map<std::string, std::string> _attributs;
    // Forme(std::vector<std::string> attributs, std::vector<std::string> valeurs);

    // Proposition ruben pour les attributs, un Struct ou une Class interne
    // Couleur couleur;
    // Couleur remplissage;
    // std::string rotation;
    // std::string opacite;
    // int epaisseur;

    Forme();
    virtual ~Forme() = default;
    // Probleme de compilation :
    // Declarer en lianson static mais pas definir
    // virtual int centreX();
    // virtual int centreY();

    void addAttribut(std::string attribut, std::string valeur);
    std::string toSVG();
};

using formePtr = std::shared_ptr<Forme>;
