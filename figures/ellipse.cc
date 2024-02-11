#include "ellipse.hh"
#include <iostream>
#include <sstream>


Ellipse::Ellipse(int posX, int posY, int hauteur, int largeur)
    : FormeSimpleCoord::FormeSimpleCoord(posX, posY), _hauteur(hauteur), _largeur(largeur) {}


std::string Ellipse::toSVG() {
    std::ostringstream out;

    out << "<ellipse cx=\"" << _posX << "\" cy=\"" << _posY << "\" rx=\"" << _largeur << "\" ry=\"" << _hauteur << "\" />";

    std::string s = out.str();

    return s;
}