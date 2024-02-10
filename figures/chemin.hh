#pragma once
#include "forme.hh"


class Chemin : public Forme {
public:
    std::vector<double> chemin;

    Chemin() = default;
    Chemin(const Chemin & r);
    ~Chemin() = default;

    void add_chemin(double x, double y);
};
