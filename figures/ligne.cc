#include "ligne.hh"

Ligne::Ligne(int x1, int y1, int x2, int y2)
: Forme::Forme(),
    positionX1(x1), positionY1(y1),
    positionX2(x2), positionY2(y2) {}

Ligne::Ligne(const Ligne & r)
: Forme::Forme(),
    positionX1(r.positionX1), positionY1(r.positionY1),
    positionX2(r.positionX2), positionY2(r.positionY2) {}


