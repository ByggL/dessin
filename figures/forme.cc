#include "forme.hh"
#include <stdexcept>
#include <iostream>
#include <sstream>


Forme::Forme() {
    attributs.couleur = std::make_unique<Couleur>("noir");
    attributs.remplissage = nullptr;
    attributs.rotation = 0;
    attributs.opacite = 1.0f;
    attributs.epaisseur = 1;
}

void Forme::addAttribut(std::string attribut, std::string valeur) {
    if(attribut == "couleur") {
        attributs.couleur = std::make_unique<Couleur>(valeur);
    }
    else if(attribut == "remplissage") {
        attributs.remplissage = std::make_unique<Couleur>(valeur);
    }
}

void Forme::addAttribut(std::string attribut, int valeur) {
    if(attribut == "rotation") {
        attributs.rotation = valeur;
    }
    else if(attribut == "opacite") {
        attributs.opacite = valeur/100;
    }
    else if(attribut == "epaisseur") {
        attributs.epaisseur = valeur;
    }
}

std::string Forme::toSVG() {  // retourne une string de type « attribut1="valeur1" attribut2="valeur2" »
    std::ostringstream out;

    out << " stroke=\"" << attributs.couleur->_couleur << "\"";

    out << " fill=\"";
    if(attributs.remplissage == nullptr) out << "none";
    else out << attributs.remplissage->_couleur;
    out << "\"";

    // pas la peine d'ajouter au SVG si les attributs ont leurs valeurs par défaut
    if(attributs.rotation != 0) {
        // trouver le moyen de choper le centre
    }

    if(attributs.opacite != 1.0f) {
        out << " opacity=\"" << attributs.opacite << "\"";
    }

    if(attributs.epaisseur != 1) {
        out << " stoke-width=\"" << attributs.epaisseur << "\" ";
    }

    std::string s = out.str();
    return s;
}
