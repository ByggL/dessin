#include "triangle.hh"
#include <iostream>
#include <sstream>


Triangle::Triangle(const Triangle & r)
    : FormeSimpleCoord::FormeSimpleCoord(r.positionX, r.positionY), hauteur(r.hauteur), largeur(r.largeur) {}


Triangle::Triangle(int posX, int posY, int hauteur, int largeur)
    : FormeSimpleCoord::FormeSimpleCoord(posX, posY), hauteur(hauteur), largeur(largeur) {}


std::string Triangle::toSVG() {
    std::ostringstream out;

    out << "<polygon points=\"" << positionX << "," << positionY << " " << (positionX+(largeur/2)) << "," << (positionY+hauteur) << " " <<
        (positionX+largeur) << "," << positionY << "\" />";

    std::string s = out.str();

    return s;
}

int Triangle::centreX() { return ((positionX + (positionX+(largeur/2)) + (positionX+largeur)) / 3); }
int Triangle::centreY() { return ((positionY + (positionY+hauteur) + positionY) / 3); }
