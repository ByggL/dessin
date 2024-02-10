#include "cercle.hh"

Cercle::Cercle(const Cercle & r)
    : Forme_simple_coord::Forme_simple_coord(r.positionX,r.positionY), rayon(r.rayon) {}


Cercle::Cercle(double x, double y, double rayon)
    : Forme_simple_coord::Forme_simple_coord(x,y), rayon(rayon) {}
