#include "forme.hh"

class Ligne : public Forme {
private:
    int _x1;
    int _y1;
    int _x2;
    int _y2;

public:
    Ligne(int x1, int y1, int x2, int y2);
    std::string toSVG();
};