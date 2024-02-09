#pragma once
#include "expression.hh"
#include "forme.hh"


class Rectangle : public Forme {
private:
    ExpressionPtr _x1;
    ExpressionPtr _y1;
    ExpressionPtr _hauteur;
    ExpressionPtr _largeur;
public:
    Rectangle(const Rectangle & r);
    Rectangle(ExpressionPtr x1, ExpressionPtr y1, ExpressionPtr hauteur, ExpressionPtr largeur);
    ~Rectangle() = default;

    std::string toSVG();
};