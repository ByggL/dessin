#include "triangle.hh"
#include <iostream>
#include <sstream>


Triangle::Triangle(const Triangle & r)
    : FormeSimpleCoord::FormeSimpleCoord(r.positionX, r.positionY), longueur(r.longueur), hauteur(r.hauteur) {}


Triangle::Triangle(int posX, int posY, int longueur, int hauteur)
    : FormeSimpleCoord::FormeSimpleCoord(posX, posY), longueur(longueur), hauteur(hauteur) {}


std::string Triangle::to_string() const {
    std::ostringstream out;

    out << "<polygon points=\""
        << (positionX - longueur) << "," << positionY << " "
        << positionX << "," << positionY << " "
        << (positionX - (longueur/2)) << "," << (positionY - hauteur)<< "\"";

    std::string s = out.str();

    return s;
}

int Triangle::centreX() { return ((positionX + (positionX+(longueur/2)) + (positionX+longueur)) / 3); }
int Triangle::centreY() { return ((positionY + (positionY+hauteur) + positionY) / 3); }
