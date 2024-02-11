#include "ellipse.hh"


Ellipse::Ellipse(const Ellipse & r)
    : Forme_simple_coord::Forme_simple_coord(r.positionX,r.positionY), hauteur(r.hauteur), largeur(r.largeur) {}


Ellipse::Ellipse(int x, int y, int hauteur, int largeur)
    : Forme_simple_coord::Forme_simple_coord(x,y), hauteur(hauteur), largeur(largeur) {}
