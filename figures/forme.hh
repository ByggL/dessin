#pragma once
#include <memory>
#include "couleur.hh"
#include "contexte.hh"
#include "attribut.hh"
#include <string>
#include <vector>
#include <map>


class Forme {
public:

    std::vector<attributPtr> _attributs;

    Forme();
    virtual ~Forme() = default;

    virtual int centreX() = 0;
    virtual int centreY() = 0;

    void addAttribut(attributPtr _attribut);
    std::string toSVG();

};

using formePtr = std::shared_ptr<Forme>;

