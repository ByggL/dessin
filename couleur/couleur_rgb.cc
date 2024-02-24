#include "couleur_rgb.hh"
#include <iostream>
#include <sstream>
#include <stdexcept>

Couleur_rgb::Couleur_rgb(int r, int g, int b)
 : Couleur::Couleur() {
    _valeur = rgb2hex(r,g,b);
}

std::string Couleur_rgb::int_to_hex(int i ) {
    std::stringstream stream;
    if (i > 15) {
        stream << std::hex << (i << 4) ;
    } else {
        stream << "0" + std::to_string(i);
    }
    return stream.str();
}

std::string Couleur_rgb::rgb2hex(int r, int g, int b) {
    if((r > 255) | (g > 255) | (b > 255) |
            (r < 0) | (g < 0) | (b < 0)){
        throw std::invalid_argument("Le RGB n'est pas correct");
    }

    std::string s = "#";
    std::string sr,sg,sb;
    s += int_to_hex(r).substr(0,2);
    s += int_to_hex(g).substr(0,2);
    s += int_to_hex(b).substr(0,2);
    return s;
}

