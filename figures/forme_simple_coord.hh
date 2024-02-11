#pragma once
#include "forme.hh"

class Forme_simple_coord {
    public:
        int positionX;
        int positionY;

        Forme_simple_coord(int x, int y);
        virtual ~Forme_simple_coord() =0;
};
