#include "texte.hh"
#include <iostream>
#include <sstream>


Texte::Texte(int posX, int posY, std::string content, std::string font)
    : FormeSimpleCoord::FormeSimpleCoord(posX, posY), content(content), font(font){}


std::string Texte::toSVG() {
    std::ostringstream out;

    out << "<text x=\"" << positionX << "\" y=\"" << positionY
        << "\" font-family=\"" << font
        << content << "</text>";

    std::string s = out.str();

    return s;
}
