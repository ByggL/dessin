#include "ellipse.hh"
#include <iostream>
#include <sstream>


Ellipse::Ellipse(const Ellipse & r)
    : FormeSimpleCoord::FormeSimpleCoord(r.positionX,r.positionY), longueur(r.longueur), hauteur(r.hauteur) {}


Ellipse::Ellipse(int posX, int posY, int longueur, int hauteur)
    : FormeSimpleCoord::FormeSimpleCoord(posX, posY), longueur(longueur), hauteur(hauteur) {}


std::string Ellipse::to_string() const {
    std::ostringstream out;

    out << "<ellipse cx=\"" << positionX << "\" cy=\"" << positionY << "\" rx=\"" << longueur << "\" ry=\"" << hauteur << "\"";

    std::string s = out.str();

    return s;
}


int Ellipse::centreX() { return positionX; }
int Ellipse::centreY() { return positionY; }
