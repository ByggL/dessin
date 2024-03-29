#pragma once
#include "formeSimpleCoord.hh"


class Texte : public FormeSimpleCoord {
public:
    std::string content;
    std::string font;

    Texte(double posX, double posY, std::string content, std::string font);
    Texte(const Texte & r);
    ~Texte() = default;
    std::string to_string() const override;

    double centreX();
    double centreY();
};
