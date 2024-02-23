#ifndef DRIVER_H

#include <string>

#include "contexte.hh"
#include "contexte_forme.hh"

class Driver {
private:
    Contexte variables;
    Contexte_forme canevas;

public:
    Driver();
    ~Driver();

    const   Contexte& getContexte() const;
    double  getVariable(const std::string& name) const;
    void    setVariable(const std::string& name, double value);

    const Contexte_forme & getForme() const;

    int getCanevasLong() const;
    int getCanevasHaut() const;
    void setCanevasLong(int l);
    void setCanevasHaut(int h);

    void ajoutFormeNomer(const std::string & s, std::shared_ptr<Forme> f);

    void ajoutForme(std::shared_ptr<Forme> f);
    void ajoutRectangle(std::shared_ptr<Forme> f);
    void ajoutCarre(std::shared_ptr<Forme> f);
    void ajoutTriangle(std::shared_ptr<Forme> f);
    void ajoutCercle(std::shared_ptr<Forme> f);
    void ajoutEllipse(std::shared_ptr<Forme> f);
    void ajoutLigne(std::shared_ptr<Forme> f);
    void ajoutChemin(std::shared_ptr<Forme> f);
    void ajoutTexte(std::shared_ptr<Forme> f);


};

#endif
