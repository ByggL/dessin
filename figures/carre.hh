#pragma once
#include "forme_simple_coord.hh"


class Carre : public Forme_simple_coord {
private:
    double taille;
public:
    Carre(const Carre & r);
    Carre(double x, double y, double taille);
    ~Carre() = default;
};
