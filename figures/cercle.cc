#include "cercle.hh"

Cercle::Cercle(const Cercle & r)
    : Forme_simple_coord::Forme_simple_coord(r.positionX,r.positionY), rayon(r.rayon) {}


Cercle::Cercle(int x, int y, int rayon)
    : Forme_simple_coord::Forme_simple_coord(x,y), rayon(rayon) {}
