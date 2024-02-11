#include "formeSimpleCoord.hh"


class Cercle : public FormeSimpleCoord {
private:
    int _rayon;

public:
    Cercle(int posX, int posY, int rayon);
    std::string toSVG();
};