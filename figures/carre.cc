#include "carre.hh"
#include <iostream>
#include <sstream>

Carre::Carre(int x, int y, int taille)
    : FormeSimpleCoord::FormeSimpleCoord(x,y), taille(taille) {}

Carre::Carre(const Carre & r)
    : FormeSimpleCoord::FormeSimpleCoord(r.positionX,r.positionY), taille(r.taille) {}


std::string Carre::toSVG() {
    std::ostringstream out;

    out << "<rect x=\"" << positionX << "\" y=\"" << positionY << "\" width=\"" << taille << "\" height=\"" << taille << "\" " << Forme::toSVG() << " />";

    std::string s = out.str();
    return s;
}
