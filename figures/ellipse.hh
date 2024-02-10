#pragma once
#include "forme_simple_coord.hh"


class Ellipse : public Forme_simple_coord {
private:
    double hauteur;
    double largeur;
public:
    Ellipse(const Ellipse & r);
    Ellipse(double x, double y, double hauteur, double largeur);
    ~Ellipse() = default;
};
