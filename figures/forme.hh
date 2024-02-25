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

    virtual double centreX() = 0;
    virtual double centreY() = 0;

    void addAttribut(attributPtr _attribut);
    virtual std::string to_string() const =0;
    std::string toSVG();

};

using formePtr = std::shared_ptr<Forme>;
using vectAttributPtr = std::vector<attributPtr>;

