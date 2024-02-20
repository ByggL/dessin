#include "couleur.hh"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <regex>

std::regex pat("#[A-F0-9]{6}");

std::string Couleur::stringColorToHex(std::string couleur) {  // convertit une couleur nommée en sa valeur hex
    if(couleur == "rouge") {
        return "#FF0000";
    }
    else if (couleur == "bleu") {
        return "#0000FF";
    }
    else if (couleur == "vert") {
        return "#008000";
    }
    else if (couleur == "jaune") {
        return "#FFFF00";
    }
    else if (couleur == "violet") {
        return "#B200ED";
    }
    else if (couleur == "magenta") {
        return "#8b008b";
    }
    else if (couleur == "cyan") {
        return "#00FFFF";
    }
    else if (couleur == "blanc") {
        return "#FFFFFF";
    }
    else if (couleur == "noir") {
        return "#000000";
    }
    else if (std::regex_match(couleur, pat)) {
        return couleur;
    }
    else {
        throw std::invalid_argument("Nom ou valeur hexadécimale de couleur invalide");
    }
}

Couleur::Couleur(std::string couleur) {
    _couleur = stringColorToHex(couleur);
}
    
Couleur::Couleur(int r, int g, int b) {
    _couleur = rgb2hex(r,g,b);
}

std::string Couleur::rgb2hex(unsigned int r, unsigned int g, unsigned int b) 
{ 
    if(r > 255 | g > 255 | b > 255){
        throw std::invalid_argument("Le RGB n'est pas correct");
    }
    std::stringstream ss;  
    ss << "#"; 
    ss << std::hex << (r << 16 | g << 8 | b ); 
    return ss.str();
}

Couleur & Couleur::operator=(std::string const & col) {
    _couleur = stringColorToHex(col);
}

bool Couleur::operator==(std::string const & col) {
    return _couleur == stringColorToHex(col);
}

bool Couleur::operator!=(std::string const & col) {
    return _couleur != stringColorToHex(col);
}