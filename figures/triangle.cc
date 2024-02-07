#include "triangle.hh"


Triangle::Triangle(const Triangle & r)
    : Forme::Forme(), _x(r._x), _y(r._y), _hauteur(r._hauteur), _largeur(r._largeur) {}


Triangle::Triangle(ExpressionPtr x, ExpressionPtr y, ExpressionPtr hauteur, ExpressionPtr largeur)
    : Forme::Forme(),_x(x), _y(y), _hauteur(hauteur), _largeur(largeur) {}