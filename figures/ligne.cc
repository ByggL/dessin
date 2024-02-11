#include "ligne.hh"
#include <iostream>
#include <sstream>


Ligne::Ligne(int x1, int y1, int x2, int y2)
    : Forme::Forme(), _x1(x1), _y1(y1), _x2(x2), _y2(y2) {}


std::string Ligne::toSVG() {
    std::ostringstream out;

    out << "<line x1=\"" << _x1 << "\" y1=\"" << _y1 << "\" x2=\"" << _x2 << "\" y2=\"" << _y2 << "\" " << Forme::toSVG() << " />"; 

    std::string s = out.str();
    return s;
}
