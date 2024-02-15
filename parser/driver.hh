#ifndef DRIVER_H
#define DRIVER_H

#include <string>

#include "contexte.hh"
#include "contexte_forme.hh"

class Driver {
private:
    Contexte variables;
    Contexte_forme formes;

public:
    Driver();
    ~Driver();

    const   Contexte& getContexte() const;
    double  getVariable(const std::string& name) const;
    void    setVariable(const std::string& name, double value);

    void ajoutCarre(std::shared_ptr<Forme> c);

};

#endif
