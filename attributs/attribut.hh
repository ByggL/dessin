#pragma once
#include "couleur.hh"
#include "contexte.hh"
#include <string>
#include <sstream>
#include <iostream>
#include <memory>


class Attribut {
public:
    Attribut();
    virtual ~Attribut() = default;

    virtual std::string type() const =0;
    virtual std::string valeur() const =0;
};
