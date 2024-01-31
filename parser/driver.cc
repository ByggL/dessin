#include "driver.hh"
#include <iostream>

Driver::Driver() {}
Driver::~Driver() {}


const Contexte& Driver::getContexte() const {
    // Retourne le contexte pour qu'il soit accessible en dehors de la classe Driver
    return variables;
}

double Driver::getVariable(const std::string & name) const {
    // Retourne la valeur de la variable name
    return variables.get(name);
}

void Driver::setVariable(const std::string & name, double value) {
    // Affecte une valeur à une variable avec l'utilisation du contexte variables
    variables[name] = value;
}

