#pragma once
#include "attribut.hh"


class AttributInt : public Attribut {
public:
    int _valeur;

    AttributInt(int val);
    std::string valeur() const override;
};
