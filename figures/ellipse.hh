#pragma once
#include "formeSimpleCoord.hh"


class Ellipse : public FormeSimpleCoord {
public:
    double longueur;
    double hauteur;

    Ellipse(double posX, double posY, double longueur, double hauteur);
    Ellipse(const Ellipse & r);
    ~Ellipse() = default;
    std::string to_string() const override;

    double centreX();
    double centreY();
};
