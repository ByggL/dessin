#include "chemin.hh"

Chemin::Chemin(const Chemin & r)
    :chemin(r.chemin){}

void Chemin::ajout(int x, int y) {
    chemin.push_back(y);
    chemin.push_back(x);
}
