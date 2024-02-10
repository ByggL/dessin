#pragma once
#include "forme_simple_coord.hh"


class Cercle : public Forme_simple_coord {
private:
    double rayon;
public:
    Cercle(const Cercle & r);
    Cercle(double x, double y, double rayon);
    ~Cercle() = default;
};
