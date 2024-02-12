#include "contexte_forme.hh"
#include <iostream>
#include <sstream>

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

std::string Contexte_forme::toSVG() {
    std::ostringstream out;

    out << "<svg version=\"1.1\" width=\"" << longueur << "\" height=\"" << hauteur
        << "xmlns=\"http://www.w3.org/2000/svg\">";

    // toSVG() de toutes formes

    out << "\n</svg>";

    std::string s = out.str();

    return s;
}