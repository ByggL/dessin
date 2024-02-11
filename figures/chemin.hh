#pragma once
#include "forme.hh"


class Chemin : public Forme {
public:
    std::vector<int> chemin;

    Chemin() = default;
    Chemin(const std::vector<int> & c);
    Chemin(const Chemin & r);
    ~Chemin() = default;

    void ajout(int x, int y);

};

using coordChemin = std::vector<int>;
