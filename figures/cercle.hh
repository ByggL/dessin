#pragma once
#include "forme_simple_coord.hh"


class Cercle : public Forme_simple_coord {
private:
    int rayon;
public:
    Cercle(const Cercle & r);
    Cercle(int x, int y, int rayon);
    ~Cercle() = default;

};
