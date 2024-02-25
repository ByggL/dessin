#include "ligne.hh"
#include <iostream>
#include <sstream>


Ligne::Ligne(double x1, double y1, double x2, double y2)
    : Forme::Forme(), positionX1(x1), positionY1(y1), positionX2(x2), positionY2(y2) {}


std::string Ligne::to_string() const {
    std::ostringstream out;

    out << "<line X1=\"" << positionX1 << "\" Y1=\"" << positionY1 << "\" X2=\"" << positionX2 << "\" Y2=\"" << positionY2 << "\"";

    std::string s = out.str();
    return s;
}


double Ligne::centreX() { return positionX1 + (positionX2/2); }
double Ligne::centreY() { return positionY1 + (positionY2/2); }
