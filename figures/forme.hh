#include "contexte_forme.hh"
#include "couleur.hh"


class Forme {
public:
    Couleur couleur;
    Couleur remplissage;
    std::string rotation;
    std::string opacite;
    double epaisseur;

    Forme() =default;
    Forme(Couleur cou, Couleur rem, std::string rot, std::string opa, std::string epa);
    virtual ~Forme() = default;

};
