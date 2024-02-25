#pragma once
#include "formeSimpleCoord.hh"


class Carre : public FormeSimpleCoord {
public:
    double taille;

    Carre(double x, double y, double taille);
    Carre(const Carre & r);
    ~Carre() = default;
    std::string to_string() const override;

    double centreX();
    double centreY();
};
