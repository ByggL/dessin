#include "chemin.hh"
#include <iostream>
#include <sstream>


Chemin::Chemin(const Chemin & r)
    :coords(r.coords){}

void Chemin::ajout(int x, int y) {
    coords.push_back(x);
    coords.push_back(y);
}

Chemin::Chemin(const std::vector<int> & c)
    : Forme::Forme(), coords(c) {}


std::string Chemin::to_string() const {
    std::ostringstream out;

    out << "<path d=\"M " << coords[0] << " " << coords[1] << " ";

    for(unsigned int i = 2; i < coords.size(); i+=2) {
        out << "L " << coords[i] << " " << coords[i+1] << " ";
    }

    out << "\"";

    std::string s = out.str();
    return s;
}

// trop complexe de calculer le centre d'un polygone irrégulier. On se contentera du point d'origine
int Chemin::centreX() { return coords[0]; }
int Chemin::centreY() { return coords[1]; }
