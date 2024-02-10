#pragma once
#include "forme_simple_coord.hh"


class Texte : public Forme_simple_coord {
private:
    std::string texte;
    std::string police;
public:
    Texte(const Texte & r);
    Texte(double x, double y, std::string texte, std::string police);
    ~Texte() = default;
};
