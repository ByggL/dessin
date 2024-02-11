#pragma once
#include "forme_simple_coord.hh"


class Ellipse : public Forme_simple_coord {
private:
    int hauteur;
    int largeur;
public:
    Ellipse(const Ellipse & r);
    Ellipse(int x, int y, int hauteur, int largeur);
    ~Ellipse() = default;
};
