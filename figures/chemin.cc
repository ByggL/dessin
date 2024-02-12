#include "chemin.hh"
#include <iostream>
#include <sstream>


Chemin::Chemin(const Chemin & r)
    :_coords(r._coords){}

void Chemin::ajout(int x, int y) {
    _coords.push_back(x);
    _coords.push_back(y);
}

Chemin::Chemin(const std::vector<int> & c)
    : Forme::Forme(), _coords(c) {}


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
