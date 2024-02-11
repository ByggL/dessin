#include "chemin.hh"
#include <iostream>
#include <sstream>

Chemin::Chemin(std::vector<double> coords)
    : Forme::Forme(), _coords(coords) {}


std::string Chemin::toSVG() {
    std::ostringstream out;

    out << "<path d=\"M " << _coords[0] << " " << _coords[1] << " ";

    for(unsigned int i = 2; i < _coords.size(); i+=2) {
        out << "L " << _coords[i] << " " << _coords[i+1] << " ";
    } 

    out << "\" " << Forme::toSVG() << " />";

    std::string s = out.str();
    return s;
}