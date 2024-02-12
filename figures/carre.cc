#include "carre.hh"
#include <iostream>
#include <sstream>

Carre::Carre(int x, int y, int taille)
    : FormeSimpleCoord::FormeSimpleCoord(x,y), _taille(taille) {}

Carre::Carre(const Carre & r)
    : FormeSimpleCoord::FormeSimpleCoord(r._posX,r._posY), _taille(r._taille) {}

// Carre & Carre::operator=(const Carre & c) {
//     if (this != &c) {
//         Forme_simple_coord(c.positionX, c.positionY);
//         taille = c.taille;
//     }
//     return *this;
// }
//

std::string Carre::toSVG() {
    std::ostringstream out;

    out << "<rect x=\"" << _posX << "\" y=\"" << _posY << "\" width=\"" << _taille << "\" height=\"" << _taille << "\" " << Forme::toSVG() << " />"; 

    std::string s = out.str();
    return s;
}