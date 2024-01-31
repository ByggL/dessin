#pragma once
#include "expression.hh"
#include "forme.hh"


class Rectangle : public Forme {
private:
    ExpressionPtr _x1;
    ExpressionPtr _y1;
    ExpressionPtr _x2;
    ExpressionPtr _y2;
    ExpressionPtr _x3;
    ExpressionPtr _y3;
    ExpressionPtr _x4;
    ExpressionPtr _y4;
public:
    Rectangle(const Rectangle &) = default;
    Rectangle(ExpressionPtr x1, ExpressionPtr y1, ExpressionPtr x2, ExpressionPtr y2, ExpressionPtr x3, ExpressionPtr y3, ExpressionPtr x4, ExpressionPtr y4);
    ~Rectangle() = default;
};