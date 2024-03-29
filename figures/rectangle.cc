#include "rectangle.hh"
#include <iostream>
#include <sstream>


Rectangle::Rectangle(const Rectangle & r)
    : Forme::Forme(), positionX1(r.positionX1), positionY1(r.positionY1), positionX2(r.positionX2), positionY2(r.positionY2), positionX3(r.positionX3), positionY3(r.positionY3), positionX4(r.positionX4), positionY4(r.positionY4) {}


Rectangle::Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : Forme::Forme(), positionX1(x1), positionY1(y1), positionX2(x2), positionY2(y2), positionX3(x3), positionY3(y3), positionX4(x4), positionY4(y4) {}


std::string Rectangle::to_string() const {
    std::ostringstream out;

    out << "<rect x=\"" << positionX1 << "\" y=\"" << positionY1 << "\" width=\"" << positionX4 - positionX1 << "\" height=\"" << (positionY2 - positionY1) << "\"";

    std::string s = out.str();
    return s;
}


double Rectangle::centreX() { return positionX1 + ((positionX4 - positionX1)/2); }
double Rectangle::centreY() { return positionY1 + ((positionY2 - positionY1)/2); }
