#include "triangle.hh"
#include <iostream>
#include <sstream>


Triangle::Triangle(const Triangle & r)
    : FormeSimpleCoord::FormeSimpleCoord(r._posX, r._posY), _hauteur(r._hauteur), _largeur(r._largeur) {}


Triangle::Triangle(int posX, int posY, int hauteur, int largeur)
    : FormeSimpleCoord::FormeSimpleCoord(posX, posY), _hauteur(hauteur), _largeur(largeur) {}


std::string Triangle::toSVG() {
    std::ostringstream out;

    out << "<polygon points=\"" << _posX << "," << _posY << " " << (_posX+(_largeur/2)) << "," << (_posY+_hauteur) << " " << 
        (_posX+_largeur) << "," << _posY << "\" />";

    std::string s = out.str();

    return s;
}