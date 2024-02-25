#include "couleur_hex.hh"
#include <stdexcept>
#include <regex>


Couleur_hex::Couleur_hex(const std::string & couleur)
    : Couleur::Couleur() {

    std::regex pat("#[a-fA-F0-9]{6}");

    if (std::regex_match(couleur, pat)) {
        _valeur = couleur;
    } else {
        throw std::invalid_argument("Valeur hexadécimale de couleur invalide");
    }

}

