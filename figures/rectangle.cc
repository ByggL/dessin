#include "rectangle.hh"
#include <iostream>
#include <sstream>


Rectangle::Rectangle(const Rectangle & r)
    : Forme::Forme(), _x1(r._x1), _y1(r._y1), _hauteur(r._hauteur), _largeur(r._largeur) {}


Rectangle::Rectangle(ExpressionPtr x1, ExpressionPtr y1, ExpressionPtr hauteur, ExpressionPtr largeur)
    : Forme::Forme(),_x1(x1), _y1(y1), _hauteur(hauteur), _largeur(largeur) {}


std::string Rectangle::toSVG() {
    std::ostringstream out;

    out << "<rect x=\"" << _x1 << "\" y=\"" << _y1 << "\" width=\"" << _largeur << "\" height=\"" << _hauteur << "\" " << Forme::toSVG() << " />"; 

    std::string s = out.str();
    return s;
}