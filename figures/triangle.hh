#pragma once
#include "formeSimpleCoord.hh"


class Triangle : public FormeSimpleCoord {
public:
    int hauteur;
    int largeur;

    Triangle(const Triangle & r);
    Triangle(int posX, int posY, int hauteur, int largeur);
    ~Triangle() = default;

    std::string toSVG();

    int centreX();
    int centreY();
};
