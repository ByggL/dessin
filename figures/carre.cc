#include "carre.hh"

Carre::Carre(const Carre & r)
    : Forme_simple_coord::Forme_simple_coord(r.positionX,r.positionY), taille(r.taille) {}


Carre::Carre(double x, double y, double taille)
    : Forme_simple_coord::Forme_simple_coord(x,y), taille(taille) {}
