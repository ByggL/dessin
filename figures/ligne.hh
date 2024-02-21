#pragma once
#include "forme.hh"

class Ligne : public Forme {
public:
    int positionX1;
    int positionY1;
    int positionX2;
    int positionY2;

    Ligne(int x1, int y1, int x2, int y2);
    Ligne(const Ligne & r);
    ~Ligne() = default;
    std::string toSVG();

    int centreX();
    int centreY();
};
