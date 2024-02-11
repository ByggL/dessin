#include "forme.hh"


class Chemin : public Forme {
private:
    std::vector<int> _coords;

public:
    Chemin(std::vector<int> coords);

    std::string toSVG();
};