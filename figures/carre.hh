#pragma once
#include "formeSimpleCoord.hh"


class Carre : public FormeSimpleCoord {
public:
    int taille;

    Carre(int x, int y, int taille);
    Carre(const Carre & r);
    ~Carre() = default;
    // Carre & operator=(const Carre & c);
    std::string toSVG();
};
