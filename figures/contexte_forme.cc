#include "contexte_forme.hh"

std::shared_ptr<Forme> Contexte_forme::get(const std::string & nom) {
    return formes_nomer[nom];
}

const std::shared_ptr<Forme> Contexte_forme::get(const std::string & nom) const {
    return formes_nomer.at(nom);
}

std::shared_ptr<Forme> Contexte_forme::operator[](const std::string & nom) {
    return formes_nomer[nom];
}

const std::shared_ptr<Forme> Contexte_forme::operator[](const std::string & nom) const {
    return formes_nomer.at(nom);
}
