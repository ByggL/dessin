#include "ellipse.hh"
#include <iostream>
#include <sstream>


Ellipse::Ellipse(const Ellipse & r)
    : FormeSimpleCoord::FormeSimpleCoord(r.positionX,r.positionY), hauteur(r.hauteur), largeur(r.largeur) {}


Ellipse::Ellipse(int posX, int posY, int hauteur, int largeur)
    : FormeSimpleCoord::FormeSimpleCoord(posX, posY), hauteur(hauteur), largeur(largeur) {}


std::string Ellipse::toSVG() {
    std::ostringstream out;

    out << "<ellipse cx=\"" << positionX << "\" cy=\"" << positionY << "\" rx=\"" << largeur << "\" ry=\"" << hauteur << "\" />";

    std::string s = out.str();

    return s;
}


int Ellipse::centreX() { return positionX; }
int Ellipse::centreY() { return positionY; }