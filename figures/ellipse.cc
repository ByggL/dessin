#include "ellipse.hh"
#include <iostream>
#include <sstream>


Ellipse::Ellipse(const Ellipse & r)
    : FormeSimpleCoord::FormeSimpleCoord(r.positionX,r.positionY), longueur(r.longueur), hauteur(r.hauteur) {}


Ellipse::Ellipse(double posX, double posY, double longueur, double hauteur)
    : FormeSimpleCoord::FormeSimpleCoord(posX, posY), longueur(longueur), hauteur(hauteur) {}


std::string Ellipse::to_string() const {
    std::ostringstream out;

    out << "<ellipse cx=\"" << positionX << "\" cy=\"" << positionY << "\" rx=\"" << longueur << "\" ry=\"" << hauteur << "\"";

    std::string s = out.str();

    return s;
}


double Ellipse::centreX() { return positionX; }
double Ellipse::centreY() { return positionY; }
