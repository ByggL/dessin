#include "couleur_nom.hh"
#include <stdexcept>

Couleur_nom::Couleur_nom(const std::string & couleur)
    : Couleur::Couleur() {

    if(couleur == "rouge") {
        _valeur = "#FF0000";
    } else if (couleur == "bleu") {
        _valeur = "#0000FF";
    } else if (couleur == "vert") {
        _valeur = "#008000";
    } else if (couleur == "jaune") {
        _valeur = "#FFFF00";
    } else if (couleur == "violet") {
        _valeur = "#7F00FF";
    } else if (couleur == "magenta") {
        _valeur = "#FF00FF";
    } else if (couleur == "cyan") {
        _valeur = "#00FFFF";
    } else if (couleur == "blanc") {
        _valeur = "#FFFFFF";
    } else if (couleur == "noir") {
        _valeur = "#000000";
    } else {
        throw std::invalid_argument("Nom de couleur invalide");
    }

}
