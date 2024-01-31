#include <string>
#include <map>
#include <vector>

class Forme {
protected:
    std::map<std::string, std::string> _attributs;
public:
    Forme(std::vector<std::string> attributs, std::vector<std::string> valeurs));
    virtual ~Forme() = default;
};