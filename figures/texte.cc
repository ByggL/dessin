#include "texte.hh"
#include <iostream>
#include <sstream>


Texte::Texte(int posX, int posY, std::string content, std::string font, int size)
    : FormeSimpleCoord::FormeSimpleCoord(posX, posY), _content(content), _font(font), _size(size) {}


std::string Texte::toSVG() {
    std::ostringstream out;

    out << "<text x=\"" << _posX << "\" y=\"" << _posY 
        << "\" font-family=\"" << _font 
        << "\" font-size=\"" << _size <<"\">" << _content << "</text>";

    std::string s = out.str();

    return s;
}