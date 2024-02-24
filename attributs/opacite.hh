#include "attributInt.hh"


class Opacite : public AttributInt {
public:
    Opacite(int val);

    std::string type() const override;
    std::string valeur() const override;
};
