#include "rectangle.hh"


Rectangle::Rectangle(const Rectangle & r)
    : Forme::Forme(), _x1(r._x1), _x2(r._x2), _x3(r._x3), _x4(r._x4), _y1(r._y1), _y2(r._y2), _y3(r._y3), _y4(r._y4) {}


Rectangle::Rectangle(ExpressionPtr x1, ExpressionPtr y1, ExpressionPtr x2, ExpressionPtr y2, ExpressionPtr x3, ExpressionPtr y3, ExpressionPtr x4, ExpressionPtr y4)
    : Forme::Forme(),_x1(x1), _x2(x2), _x3(x3), _x4(x4), _y1(y1), _y2(y2), _y3(y3), _y4(y4) {}