#include <string>
#include <map>
#include <any>

class Forme {
protected:
    std::map<std::string, std::any> attributs;
    std::string couleur;
    int rotation;
    std::string remplissage;
    unsigned int opacite;
    unsigned int epaisseur;
public:
    Forme(std::string couleur = "black", int rotation = 0, std::string remplissage = "none", unsigned int opacite = 100, unsigned int epaisseur = 1);
    virtual ~Forme() = default;
};