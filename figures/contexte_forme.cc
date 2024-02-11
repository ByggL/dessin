#include "contexte_forme.hh"

std::shared_ptr<Forme> Contexte_forme::get(const std::string & nom) {
    return variables[nom];
}

const std::shared_ptr<Forme> Contexte_forme::get(const std::string & nom) const {
    return variables.at(nom);
}

std::shared_ptr<Forme> Contexte_forme::operator[](const std::string & nom) {
    return variables[nom];
}

const std::shared_ptr<Forme> Contexte_forme::operator[](const std::string & nom) const {
    return variables.at(nom);
}
