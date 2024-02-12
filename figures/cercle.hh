#pragma once

#include "formeSimpleCoord.hh"


class Cercle : public FormeSimpleCoord {
private:
    int _rayon;

public:
    Cercle(int posX, int posY, int rayon);
    Cercle(const Cercle & r);
    ~Cercle() = default;
    std::string toSVG();
};
