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

void Driver::ajoutCarre(std::shared_ptr<Forme> c) {
    canevas.carres.push_back(c);
}
