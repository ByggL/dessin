#pragma once
#include "expression.hh"
#include "forme.hh"


class Rectangle : public Forme {
private:
    double _x1;
    double _y1;
    double _hauteur;
    double _largeur;
public:
    Rectangle(const Rectangle & r);
    Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    ~Rectangle() = default;

    std::string toSVG();
};