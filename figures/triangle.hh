#pragma once
#include "forme_simple_coord.hh"


class Triangle : public Forme_simple_coord {
private:
    int hauteur;
    int largeur;
public:
    Triangle(const Triangle & r);
    Triangle(int x, int y, int hauteur, int largeur);
    ~Triangle() = default;

};
