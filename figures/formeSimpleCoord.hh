#pragma once
#include "forme.hh"


class FormeSimpleCoord : public Forme {
public:
    double positionX;
    double positionY;

    FormeSimpleCoord(double posX, double posY);

    virtual double centreX() = 0;
    virtual double centreY() = 0;
};
