#pragma once
#include "formeSimpleCoord.hh"


class Cercle : public FormeSimpleCoord {
public:
    int rayon;

    Cercle(int positionX, int positionY, int rayon);
    Cercle(const Cercle & r);
    ~Cercle() = default;
    std::string toSVG();

    int centreX();
    int centreY();
};
