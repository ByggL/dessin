#pragma once
#include "formeSimpleCoord.hh"


class Texte : public FormeSimpleCoord {
public:
    std::string content;
    std::string font;

    Texte(int posX, int posY, std::string content, std::string font);
    Texte(const Texte & r);
    ~Texte() = default;
    std::string toSVG();

    int centreX();
    int centreY();
};
