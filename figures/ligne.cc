#include "ligne.hh"

Ligne::Ligne(double x1, double y1, double x2, double y2)
: Forme::Forme(),positionX1(x1), positionX2(x2), positionY1(y1), positionY2(y2) {}

Ligne::Ligne(const Ligne & r)
: Forme::Forme(), positionX1(r.positionX1), positionX2(r.positionX2), positionY1(r.positionY1), positionY2(r.positionY2) {}


