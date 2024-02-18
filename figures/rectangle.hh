#pragma once
#include "forme.hh"


class Rectangle : public Forme {
public:
    int positionX1;
    int positionY1;
    int positionX2;
    int positionY2;
    int positionX3;
    int positionY3;
    int positionX4;
    int positionY4;


    Rectangle(const Rectangle & r);
    Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
    ~Rectangle() = default;

    int centreX();
    int centreY();

    std::string toSVG();
};
