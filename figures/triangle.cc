#include "triangle.hh"


Triangle::Triangle(const Triangle & r)
    : Forme_simple_coord::Forme_simple_coord(r.positionX,r.positionY), hauteur(r.hauteur), largeur(r.largeur) {}


Triangle::Triangle(double x, double y, double hauteur, double largeur)
    : Forme_simple_coord::Forme_simple_coord(x,y), hauteur(hauteur), largeur(largeur) {}
