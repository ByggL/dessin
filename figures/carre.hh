#pragma once
#include "forme_simple_coord.hh"


class Carre : public Forme_simple_coord {
private:
    int taille;
public:
    Carre(const Carre & r);
    Carre(int x, int y, int taille);
    ~Carre() = default;

};
