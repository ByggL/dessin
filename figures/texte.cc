#include "texte.hh"

Texte::Texte(const Texte & r)
    : Forme_simple_coord::Forme_simple_coord(r.positionX,r.positionY), texte(r.texte), police(r.police) {}


Texte::Texte(int x, int y, const std::string & texte, const std::string & police)
    : Forme_simple_coord::Forme_simple_coord(x,y), texte(texte), police(police) {}
