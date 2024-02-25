#include "texte.hh"
#include <iostream>
#include <sstream>


Texte::Texte(double posX, double posY, std::string content, std::string font)
    : FormeSimpleCoord::FormeSimpleCoord(posX, posY), content(content), font(font){}


std::string Texte::to_string() const {
    std::ostringstream out;

    out << "<text x=\"" << positionX << "\" y=\"" << positionY
        << "\" font-family=\"" << font;

    std::string s = out.str();

    return s;
}


double Texte::centreX() { return positionX; }  // on s'embête pas à aller chercher le centre du texte
double Texte::centreY() { return positionY; }
