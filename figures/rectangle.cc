#include "rectangle.hh"


Rectangle::Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
: Forme::Forme(),positionX1(x1), positionX2(x2), positionX3(x3), positionX4(x4), positionY1(y1), positionY2(y2), positionY3(y3), positionY4(y4) {}

Rectangle::Rectangle(const Rectangle & r)
: Forme::Forme(), positionX1(r.positionX1), positionX2(r.positionX2), positionX3(r.positionX3), positionX4(r.positionX4), positionY1(r.positionY1), positionY2(r.positionY2), positionY3(r.positionY3), positionY4(r.positionY4) {}


