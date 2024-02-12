#include "ellipse.hh"
#include <iostream>
#include <sstream>


Ellipse::Ellipse(const Ellipse & r)
    : FormeSimpleCoord::FormeSimpleCoord(r._posX,r._posY), _hauteur(r._hauteur), _largeur(r._largeur) {}


Ellipse::Ellipse(int x, int y, int hauteur, int largeur)
    : FormeSimpleCoord::FormeSimpleCoord(x,y), _hauteur(hauteur), _largeur(largeur) {}



Ellipse::Ellipse(int posX, int posY, int hauteur, int largeur)
    : FormeSimpleCoord::FormeSimpleCoord(posX, posY), _hauteur(hauteur), _largeur(largeur) {}


std::string Ellipse::toSVG() {
    std::ostringstream out;

    out << "<ellipse cx=\"" << _posX << "\" cy=\"" << _posY << "\" rx=\"" << _largeur << "\" ry=\"" << _hauteur << "\" />";

    std::string s = out.str();

    return s;
}
