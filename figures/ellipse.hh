
#pragma once
#include "formeSimpleCoord.hh"


class Ellipse : public FormeSimpleCoord {
private:
    int _largeur;
    int _hauteur;

public:
    Ellipse(int posX, int posY, int hauteur, int largeur);
    Ellipse(const Ellipse & r);
    ~Ellipse() = default;
    std::string toSVG();
};
