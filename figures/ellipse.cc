#include "ellipse.hh"
#include <iostream>
#include <sstream>


Ellipse::Ellipse(const Ellipse & r)
    : FormeSimpleCoord::FormeSimpleCoord(r.positionX,r.positionY), hauteur(r.hauteur), largeur(r.largeur) {}


Ellipse::Ellipse(int x, int y, int hauteur, int largeur)
    : FormeSimpleCoord::FormeSimpleCoord(x,y), hauteur(hauteur), largeur(largeur) {}



Ellipse::Ellipse(int posX, int posY, int hauteur, int largeur)
    : FormeSimpleCoord::FormeSimpleCoord(posX, posY), _hauteur(hauteur), _largeur(largeur) {}


std::string Ellipse::toSVG() {
    std::ostringstream out;

    out << "<ellipse cx=\"" << _posX << "\" cy=\"" << _posY << "\" rx=\"" << _largeur << "\" ry=\"" << _hauteur << "\" />";

    std::string s = out.str();

    return s;
}
