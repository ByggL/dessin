#pragma once
#include "formeSimpleCoord.hh"


class Ellipse : public FormeSimpleCoord {
public:
    int longueur;
    int hauteur;

    Ellipse(int posX, int posY, int longueur, int hauteur);
    Ellipse(const Ellipse & r);
    ~Ellipse() = default;
    std::string to_string() const override;

    int centreX();
    int centreY();
};
