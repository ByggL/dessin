#include "couleur.hh"
#include<iostream>
#include <sstream>


Couleur::Couleur(std::string couleur) {
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
}
    
Couleur::Couleur(int r, int g, int b) {
    _couleur = rgb2hex(r,g,b);
}

std::string Couleur::rgb2hex(int r, int g, int b) 
{ 
    std::stringstream ss;  
    ss << "#"; 
    ss << std::hex << (r << 16 | g << 8 | b ); 
    return ss.str();
}