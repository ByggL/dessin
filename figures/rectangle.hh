#pragma once
#include "forme.hh"


class Rectangle : public Forme {
private:
    int _x1;
    int _y1;
    int _hauteur;
    int _largeur;
public:
    Rectangle(const Rectangle & r);
    Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
    ~Rectangle() = default;

    std::string toSVG();
};
