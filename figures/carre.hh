#pragma once
#include "formeSimpleCoord.hh"


class Carre : public FormeSimpleCoord {
public:
    int taille;

    Carre(int x, int y, int taille);
    Carre(const Carre & r);
    ~Carre() = default;
    std::string to_string() const override;

    int centreX();
    int centreY();
};
