#pragma once
#include "formeSimpleCoord.hh"


class Ellipse : public FormeSimpleCoord {
public:
    int hauteur;
    int largeur;

    Ellipse(int posX, int posY, int hauteur, int largeur);
    Ellipse(const Ellipse & r);
    ~Ellipse() = default;
    std::string to_string() const override;

    int centreX();
    int centreY();
};
