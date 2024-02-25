#pragma once
#include "formeSimpleCoord.hh"


class Cercle : public FormeSimpleCoord {
public:
    double rayon;

    Cercle(double positionX, double positionY, double rayon);
    Cercle(const Cercle & r);
    ~Cercle() = default;
    std::string to_string() const override;

    double centreX();
    double centreY();
};
