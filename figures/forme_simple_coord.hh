#pragma once
#include "forme.hh"

class Forme_simple_coord {
    public:
        double positionX;
        double positionY;

        Forme_simple_coord(double x, double y);
        virtual ~Forme_simple_coord() =0;
}
