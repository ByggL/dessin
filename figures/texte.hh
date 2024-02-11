#include "formeSimpleCoord.hh"


class Texte : public FormeSimpleCoord {
private:
    std::string _content;
    std::string _font;
    int _size;
public:
    Texte(int posX, int posY, std::string content, std::string font, int size);
    std::string toSVG();
};