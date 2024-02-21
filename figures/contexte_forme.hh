#pragma once
#include <iostream>
#include <fstream>
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
    // TODO : Faire une methode pour faire modifier longueur et hauteur

    // Utilisation de variable :
    // C1 = carré 0 0 50 -> couleur : rouge & opacité : 30%
    std::map<std::string, std::shared_ptr<Forme>> formes_nomer;

    // Pour parcourir tous les formes créer i.e." sortie en svg
    std::vector<std::shared_ptr<Forme>>     formes;

    // Utilisation de l'indice dans l'ordre de création :
    // carre[0], carre[1], etc...
    std::vector<std::shared_ptr<Forme>> rectangles;
    std::vector<std::shared_ptr<Forme>>     carres;
    std::vector<std::shared_ptr<Forme>>  triangles;
    std::vector<std::shared_ptr<Forme>>    cercles;
    std::vector<std::shared_ptr<Forme>>   ellipses;
    std::vector<std::shared_ptr<Forme>>     lignes;
    std::vector<std::shared_ptr<Forme>>     textes;
    std::vector<std::shared_ptr<Forme>>    chemins;


    Contexte_forme() = default;
    Contexte_forme(const Contexte_forme & autre) = default;

    std::shared_ptr<Forme> get(const std::string & nom);
    const std::shared_ptr<Forme> get(const std::string & nom) const;

    std::shared_ptr<Forme> operator[](const std::string & nom);
    const std::shared_ptr<Forme> operator[](const std::string & nom) const;

    std::string toSVG();
    void writeToSvgFile(std::string SVGtext);
};

