#include "couleur.hh"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <regex>

std::regex pat("#[A-F0-9]{6}");


Couleur::Couleur(const std::string & couleur) {
    if(couleur == "rouge") {
        _couleur = "#FF0000";
    }
    else if (couleur == "bleu") {
        _couleur = "#0000FF";
    }
    else if (couleur == "vert") {
        _couleur = "#008000";
    }
    else if (couleur == "jaune") {
        _couleur = "#FFFF00";
    }
    else if (couleur == "blanc") {
        _couleur = "#FFFFFF";
    }
    else if (couleur == "noir") {
        _couleur = "#000000";
    }
    else if (std::regex_match(couleur, pat)) {
        _couleur = couleur;
    }
    else {
        throw std::invalid_argument("Nom ou valeur hexadécimale de couleur invalide");
    }
}

Couleur::Couleur(int r, int g, int b) {
    _couleur = rgb2hex(r,g,b);
}

Couleur::Couleur(const Couleur & col)
    : _couleur(col._couleur) {}

std::string Couleur::rgb2hex(int r, int g, int b)
{
    if((r > 255) | (g > 255) | (b > 255)){
        throw std::invalid_argument("Le RGB n'est pas correct");
    }
    std::stringstream ss;
    ss << "#";
    ss << std::hex << (r << 16 | g << 8 | b );
    return ss.str();
}
