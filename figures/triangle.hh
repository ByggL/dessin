#pragma once
#include "formeSimpleCoord.hh"


class Triangle : public FormeSimpleCoord {
private:
    int _hauteur;
    int _largeur;
public:
    Triangle(const Triangle & r);
    Triangle(int posX, int posY, int hauteur, int largeur);
    ~Triangle() = default;

    std::string toSVG();
};
