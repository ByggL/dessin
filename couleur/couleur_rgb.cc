#include "couleur_rgb.hh"
#include <iostream>
#include <sstream>
#include <stdexcept>

Couleur_rgb::Couleur_rgb(int r, int g, int b)
 : Couleur::Couleur() {
    _valeur = rgb2hex(r,g,b);
}

std::string Couleur_rgb::rgb2hex(int r, int g, int b)
{
    if((r > 255) | (g > 255) | (b > 255)){
        throw std::invalid_argument("Le RGB n'est pas correct");
    }
    std::stringstream ss;
    ss << "#";
    ss << std::hex << (r << 16 | g << 8 | b );
    return ss.str();
}
