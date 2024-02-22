#include "forme.hh"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "attribut.hh"
#include "stroke.hh"
#include "fill.hh"
#include "opacite.hh"
#include "epaisseur.hh"
#include "rotation.hh"


Forme::Forme() {}

void Forme::addAttribut(std::shared_ptr<Attribut> attribut) {
    _attributs.push_back(attribut);
}


std::string Forme::toSVG() {  // retourne une string de type « attribut1="valeur1" attribut2="valeur2" »
    std::string s = "";
    bool isStroke, isFill;
    isStroke = isFill = false;

    // TODO : checker de quel type d'attribut est chaque instance dans attributs
    for(unsigned int i = 0; i < _attributs.size(); i++) {
        if (_attributs[i]->type() == "rotate") {
            s += " tranform=\"rotate(" + _attributs[i]->valeur() + "," + std::to_string(centreX()) + "," + std::to_string(centreY()) + "\"";
        } else {
            s +=  _attributs[i]->type() + "=\"" + _attributs[i]->valeur() + "\"";
        }

        if (_attributs[i]->type() == "fill") {
            isFill = true;
        }

        if (_attributs[i]->type() == "stroke") {
            isStroke = true;
        }
    }
    // TODO : ajouter le cas où il n'y a PAS d'attribut fill

    if (!isStroke) {
        s = "stroke=\"black\"" + s;
    }

    if (!isFill) {
        s = "fill=\"none\"" + s;
    }


    return s;
}
