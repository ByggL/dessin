#include "rectangle.hh"
#include <iostream>
#include <sstream>


Rectangle::Rectangle(const Rectangle & r)
    : Forme::Forme(), _x1(r._x1), _y1(r._y1), _hauteur(r._hauteur), _largeur(r._largeur) {}


Rectangle::Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : Forme::Forme(), _x1(x1), _y1(y1) {
        _hauteur = x2 - x1;
        _largeur = y4 - y1;
    }


std::string Rectangle::toSVG() {
    std::ostringstream out;

    out << "<rect x=\"" << _x1 << "\" y=\"" << _y1 << "\" width=\"" << _largeur << "\" height=\"" << _hauteur << "\" " << Forme::toSVG() << " />"; 

    std::string s = out.str();
    return s;
}