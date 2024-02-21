#pragma once
#include "forme.hh"


class FormeSimpleCoord : public Forme {
public:
    int positionX;
    int positionY;

    FormeSimpleCoord(int posX, int posY);

    virtual int centreX() = 0;
    virtual int centreY() = 0;
};
