#include "cercle.hh"

#include <iostream>
#include <sstream>


Cercle::Cercle(int posX, int posY, int rayon)
    : FormeSimpleCoord::FormeSimpleCoord(posX, posY), rayon(rayon) {}


std::string Cercle::toSVG() {
    std::ostringstream out;

    out << "<circle cx=\"" << FormeSimpleCoord::positionX << "\" cy=\"" << FormeSimpleCoord::positionY << "\" r=\"" << rayon << "\" />";

    std::string s = out.str();

    return s;
}
