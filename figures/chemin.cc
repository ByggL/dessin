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


std::string Chemin::toSVG() {
    std::ostringstream out;

    out << "<path d=\"M " << coords[0] << " " << coords[1] << " ";

    for(unsigned int i = 2; i < coords.size(); i+=2) {
        out << "L " << coords[i] << " " << coords[i+1] << " ";
    }

    out << "\" " << Forme::toSVG() << " />";

    std::string s = out.str();
    return s;
}
