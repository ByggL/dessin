#include "carre.hh"
#include <iostream>
#include <sstream>

Carre::Carre(double x, double y, double taille)
    : FormeSimpleCoord::FormeSimpleCoord(x,y), taille(taille) {}

Carre::Carre(const Carre & r)
    : FormeSimpleCoord::FormeSimpleCoord(r.positionX,r.positionY), taille(r.taille) {}


std::string Carre::to_string() const{
    std::ostringstream out;

    out << "<rect x=\"" << positionX << "\" y=\"" << positionY << "\" width=\"" << taille << "\" height=\"" << taille << "\"";

    std::string s = out.str();
    return s;
}


double Carre::centreX() { return positionX + (taille/2); }
double Carre::centreY() { return positionY + (taille/2); }
