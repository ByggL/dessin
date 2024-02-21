#include "attributCouleur.hh"

class Stroke : public AttributCouleur {
public:
    Stroke(const Couleur & col);
    Stroke(std::string col);
};