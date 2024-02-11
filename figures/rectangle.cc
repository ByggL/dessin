#include "rectangle.hh"


Rectangle::Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
: Forme::Forme(),
    positionX1(x1), positionY1(y1),
    positionX2(x2), positionY2(y2),
    positionX3(x3), positionY3(y3),
    positionX4(x4), positionY4(y4) {}

Rectangle::Rectangle(const Rectangle & r)
: Forme::Forme(),
    positionX1(r.positionX1), positionY1(r.positionY1),
    positionX2(r.positionX2), positionY2(r.positionY2),
    positionX3(r.positionX3), positionY3(r.positionY3),
    positionX4(r.positionX4), positionY4(r.positionY4) {}


