#pragma once
#include "forme_simple_coord.hh"


class Texte : public Forme_simple_coord {
private:
    std::string texte;
    std::string police;
public:
    Texte(const Texte & r);
    Texte(int x, int y, const std::string & texte, const std::string & police);
    ~Texte() = default;

};
