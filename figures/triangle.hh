#pragma once
#include "expression.hh"
#include "forme.hh"


class Triangle : public Forme {
private:
    ExpressionPtr _x;
    ExpressionPtr _y;
    ExpressionPtr _hauteur;
    ExpressionPtr _largeur;
public:
    Triangle(const Triangle & r);
    Triangle(ExpressionPtr x, ExpressionPtr y, ExpressionPtr hauteur, ExpressionPtr largeur);
    ~Triangle() = default;
};