#include "forme.hh"


class FormeSimpleCoord : public Forme {
protected:
    int _posX;
    int _posY;
public:
    FormeSimpleCoord(int posX, int posY);
};