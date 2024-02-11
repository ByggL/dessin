#pragma once
#include "carre.hh"
#include "rectangle.hh"
#include "triangle.hh"
#include "cercle.hh"
#include "ellipse.hh"
#include "ligne.hh"
#include "texte.hh"
#include "chemin.hh"


class Contexte_forme {
public:
    int longueur;
    int hauteur;

    // Utilisation de variable :
    // C1 = carré 0 0 50 -> couleur : rouge & opacité : 30%
    std::map<std::string, std::shared_ptr<Forme>> formes_nomer;

    // Utilisation de l'indice dans l'ordre de création :
    // C[0], C[1], etc...
    std::vector<std::shared_ptr<Rectangle>> rectangles;
    std::vector<std::shared_ptr<Carre>>     carres;
    std::vector<std::shared_ptr<Cercle>>    cercles;
    std::vector<std::shared_ptr<Ellipse>>   ellipses;
    std::vector<std::shared_ptr<Ligne>>     lignes;
    std::vector<std::shared_ptr<Texte>>     textes;
    std::vector<std::shared_ptr<Chemin>>    chemins;


    Contexte_forme() = default;
    Contexte_forme(const Contexte_forme & autre) = default;

    std::shared_ptr<Forme> get(const std::string & nom);
    const std::shared_ptr<Forme> get(const std::string & nom) const;

    std::shared_ptr<Forme> operator[](const std::string & nom);
    const std::shared_ptr<Forme> operator[](const std::string & nom) const;



};

