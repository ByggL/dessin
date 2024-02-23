#include "carre.hh"
#include <iostream>
#include <sstream>

Carre::Carre(int x, int y, int taille)
    : FormeSimpleCoord::FormeSimpleCoord(x,y), taille(taille) {}

Carre::Carre(const Carre & r)
    : FormeSimpleCoord::FormeSimpleCoord(r.positionX,r.positionY), taille(r.taille) {}


std::string Carre::to_string() const{
    std::ostringstream out;

    out << "<rect x=\"" << positionX << "\" y=\"" << positionY << "\" width=\"" << taille << "\" height=\"" << taille << "\"";

    std::string s = out.str();
    return s;
}


int Carre::centreX() { return positionX + (taille/2); }
int Carre::centreY() { return positionY + (taille/2); }
