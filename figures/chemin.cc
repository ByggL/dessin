#include "chemin.hh"

Chemin::Chemin(const Chemin & r)
    :chemin(r.chemin);

void Chemin::add_chemin(double x, double y) {
    chemin.push_back(y);
    chemin.push_back(x);
}
