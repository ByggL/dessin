#include "forme.hh"

class Ligne : public Forme {
private:
    double _x1;
    double _y1;
    double _x2;
    double _y2;

public:
    Ligne(double x1, double y1, double x2, double y2);
    std::string toSVG();
};