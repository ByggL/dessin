#include "cercle.hh"

#include <iostream>
#include <sstream>


Cercle::Cercle(double posX, double posY, double rayon)
    : FormeSimpleCoord::FormeSimpleCoord(posX, posY), rayon(rayon) {}


std::string Cercle::to_string() const{
    std::ostringstream out;

    out << "<circle cx=\"" << FormeSimpleCoord::positionX << "\" cy=\"" << FormeSimpleCoord::positionY << "\" r=\"" << rayon << "\"";

    std::string s = out.str();

    return s;
}


double Cercle::centreX() { return positionX; }
double Cercle::centreY() { return positionY; }
