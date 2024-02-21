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
    attributs.push_back(attribut);
}

std::string Forme::toSVG() {  // retourne une string de type « attribut1="valeur1" attribut2="valeur2" »
    std::ostringstream out;

    // TODO : checker de quel type d'attribut est chaque instance dans attributs
    for(unsigned int i = 0; i < attributs.size(); i++) {
        if (/*attributs[i] == classe stroke*/) {
            out << " stroke=\"" << std::dynamic_pointer_cast<Stroke>(attributs[i])->valeur._couleur << "\"";
        }
        else if (/*attributs[i] == classe fill*/) {
            out << " fill=\"" << std::dynamic_pointer_cast<Fill>(attributs[i])->valeur._couleur << "\"";
        }
        else if (/*attributs[i] == classe epaisseur*/) {
            out << " stoke-width=\"" << std::dynamic_pointer_cast<Epaisseur>(attributs[i])->valeur << "\"";
        }
        else if (/*attributs[i] == classe opacite*/) {
            out << " opacity=\"" << std::dynamic_pointer_cast<Opacite>(attributs[i])->valeur << "\"";
        }
        else if (/*attributs[i] == classe rotation*/) {
            out << " tranform=\"rotate(" << std::dynamic_pointer_cast<Rotation>(attributs[i])->valeur << "," << centreX() << "," << centreY() << "\"";
        }
    }
    // TODO : ajouter le cas où il n'y a PAS d'attribut fill


    std::string s = out.str();
    return s;
}
