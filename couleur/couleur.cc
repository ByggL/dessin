#include "couleur.hh"


Couleur::Couleur(const std::string & valeur)
    : _valeur(valeur) {}

Couleur::Couleur(const Couleur & col)
    : _valeur(col._valeur) {}

