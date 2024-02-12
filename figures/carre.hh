#pragma once
#include "forme_simple_coord.hh"


class Carre : public Forme_simple_coord {
private:
    int taille;
public:
    Carre(int x, int y, int taille);
    Carre(const Carre & r);
    ~Carre() = default;
    // Carre & operator=(const Carre & c);

};
