#include "driver.hh"
#include <iostream>

Driver::Driver() {}
Driver::~Driver() {}

const Contexte& Driver::getContexte() const {
    //TODO Retourne le contexte pour qu'il soit accessible en dehors de la classe Driver
    return variables;
}

double Driver::getVariable(const std::string & name) const {
    //TODO Retourne la valeur de la variable name
    return variables.get(name);
}

void Driver::setVariable(const std::string & name, double value) {
    //TODO Affecte une valeur à une variable avec l'utilisation du contexte variables
    variables[name] = value;
}

int Driver::getCanevasLong() const {
    return canevas.longueur;
}

int Driver::getCanevasHaut() const {
    return canevas.hauteur;
}

void Driver::setCanevasLong(int l) {
    canevas.longueur = l;
}

void Driver::setCanevasHaut(int h) {
    canevas.hauteur = h;
}

void Driver::ajoutFormeNomer(const std::string & s, std::shared_ptr<Forme> f) {
    canevas.formes_nomer[s] = f;
}

void Driver::ajoutForme(std::shared_ptr<Forme> f) {
    canevas.formes.push_back(f);
}

void Driver::ajoutRectangle(std::shared_ptr<Forme> f) {
    canevas.rectangles.push_back(f);
}

void Driver::ajoutCarre(std::shared_ptr<Forme> f) {
    canevas.carres.push_back(f);
}

void Driver::ajoutTriangle(std::shared_ptr<Forme> f) {
    canevas.triangles.push_back(f);
}

void Driver::ajoutCercle(std::shared_ptr<Forme> f) {
    canevas.cercles.push_back(f);
}

void Driver::ajoutEllipse(std::shared_ptr<Forme> f) {
    canevas.ellipses.push_back(f);
}

void Driver::ajoutLigne(std::shared_ptr<Forme> f) {
    canevas.lignes.push_back(f);
}

void Driver::ajoutTexte(std::shared_ptr<Forme> f) {
    canevas.textes.push_back(f);
}

void Driver::ajoutChemin(std::shared_ptr<Forme> f) {
    canevas.chemins.push_back(f);
}

