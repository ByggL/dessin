#include "carre.hh"

Carre::Carre(int x, int y, int taille)
    : Forme_simple_coord::Forme_simple_coord(x,y), taille(taille) {}

Carre::Carre(const Carre & r)
    : Forme_simple_coord::Forme_simple_coord(r.positionX,r.positionY), taille(r.taille) {}

// Carre & Carre::operator=(const Carre & c) {
//     if (this != &c) {
//         Forme_simple_coord(c.positionX, c.positionY);
//         taille = c.taille;
//     }
//     return *this;
// }
//
