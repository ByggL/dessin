#include "forme.hh"


class Chemin : public Forme {
private:
    std::vector<double> _coords;

public:
    Chemin(std::vector<double> coords);

    std::string toSVG();
};