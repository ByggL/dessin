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

    for(unsigned int i = 0; i < formes.size(); i++) {
        out << formes[i]->toSVG();
    }

    out << "\n</svg>";

    std::string s = out.str();

    return s;
}

void writeToSvgFile(std::string SVGtext) {
    // Create the file
    std::ofstream MyFile("output.svg");

    // Write to the file
    MyFile << SVGtext;

    // Close the file

    MyFile.close();
}
