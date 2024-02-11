#include "carre.hh"

Carre::Carre(const Carre & r)
    : Forme_simple_coord::Forme_simple_coord(r.positionX,r.positionY), taille(r.taille) {}


Carre::Carre(int x, int y, int taille)
    : Forme_simple_coord::Forme_simple_coord(x,y), taille(taille) {}
