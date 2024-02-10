#pragma once
#include "forme.hh"


class Ligne : public Forme {
public:
    double positionX1;
    double positionY1;
    double positionX2;
    double positionY2;

    Ligne(double x1, double y1, double x2, double y2);
    Ligne(const Ligne & r);
    ~Ligne() = default;
};
