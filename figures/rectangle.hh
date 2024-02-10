#pragma once
#include "forme.hh"


class Rectangle : public Forme {
public:
    double positionX1;
    double positionY1;
    double positionX2;
    double positionY2;
    double positionX3;
    double positionY3;
    double positionX4;
    double positionY4;

    Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    Rectangle(const Rectangle & r);
    ~Rectangle() = default;
};
