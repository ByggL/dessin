#pragma once
#include "formeSimpleCoord.hh"


class Triangle : public FormeSimpleCoord {
public:
    double longueur;
    double hauteur;

    Triangle(const Triangle & r);
    Triangle(double posX, double posY, double longueur, double hauteur);
    ~Triangle() = default;

    std::string to_string() const override;

    double centreX();
    double centreY();
};
