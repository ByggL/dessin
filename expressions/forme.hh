#include <string>
#include <map>
#include <vector>

class Forme {
protected:
    std::map<std::string, std::string> _attributs;
public:
    Forme(std::vector<std::string> attributs, std::vector<std::string> valeurs);
    Forme();
    virtual ~Forme() = default;

    void addAttribut(std::string attribut, std::string valeur);
};