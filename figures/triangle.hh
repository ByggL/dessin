#pragma once
#include "forme_simple_coord.hh"


class Triangle : public Forme_simple_coord {
private:
    double hauteur;
    double largeur;
public:
    Triangle(const Triangle & r);
    Triangle(double x, double y, double hauteur, double largeur);
    ~Triangle() = default;
};
