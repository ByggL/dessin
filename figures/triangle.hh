#pragma once
#include "formeSimpleCoord.hh"


class Triangle : public FormeSimpleCoord {
public:
    int longueur;
    int hauteur;

    Triangle(const Triangle & r);
    Triangle(int posX, int posY, int longueur, int hauteur);
    ~Triangle() = default;

    std::string to_string() const override;

    int centreX();
    int centreY();
};
