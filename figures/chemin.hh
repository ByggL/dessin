#pragma once
#include "forme.hh"

class Chemin : public Forme {
public:
    std::vector<int> _coords;

    Chemin() = default;
    Chemin(const std::vector<int> & c);
    Chemin(const Chemin & r);
    ~Chemin() = default;

    void ajout(int x, int y);

    std::string toSVG();
};