#pragma once
#include "attributInt.hh"


class Epaisseur : public AttributInt {
public:
    Epaisseur(int val);

    std::string type() const override;
};
