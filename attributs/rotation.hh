#pragma once
#include "attributInt.hh"


class Rotation : public AttributInt {
public:
    Rotation(int val);

    std::string type() const override;
};
