#include "rectangle.hh"
#include <iostream>
#include <sstream>


Rectangle::Rectangle(const Rectangle & r)
    : Forme::Forme(), positionX1(r.positionX1), positionY1(r.positionY1), positionX2(r.positionX2), positionY2(r.positionY2), positionX3(r.positionX3), positionY3(r.positionY3), positionX4(r.positionX4), positionY4(r.positionY4) {}


Rectangle::Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
    : Forme::Forme(), positionX1(x1), positionY1(y1), positionX2(x2), positionY2(y2), positionX3(x3), positionY3(y3), positionX4(x4), positionY4(y4) {}


std::string Rectangle::toSVG() {
    std::ostringstream out;

    out << "<rect x=\"" << positionX1 << "\" y=\"" << positionY1 << "\" width=\"" << positionX2 - positionX1 << "\" height=\"" << positionY1 - positionY4 << "\" " << Forme::toSVG() << " />";

    std::string s = out.str();
    return s;
}


int Rectangle::centreX() { return positionX1 + ((positionX2 - positionX1)/2); }
int Rectangle::centreY() { return positionY1 + ((positionY1 - positionY4)/2); }