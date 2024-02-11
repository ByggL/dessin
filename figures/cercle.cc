#include "cercle.hh"
#include <iostream>
#include <sstream>


Cercle::Cercle(int posX, int posY, int rayon)
    : FormeSimpleCoord::FormeSimpleCoord(posX, posY), _rayon(rayon) {}


std::string Cercle::toSVG() {
    std::ostringstream out;

    out << "<circle cx=\"" << FormeSimpleCoord::_posX << "\" cy=\"" << FormeSimpleCoord::_posY << "\" r=\"" << _rayon << "\" />";

    std::string s = out.str();

    return s;
} 