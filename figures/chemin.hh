#pragma once
#include "forme.hh"

class Chemin : public Forme {
public:
    std::vector<double> coords;

    Chemin() = default;
    Chemin(const std::vector<double> & c);
    Chemin(const Chemin & r);
    ~Chemin() = default;

    void ajout(double x, double y);

    std::string to_string() const override;

    double centreX();
    double centreY();
};

using coordChemin = std::vector<double>;
