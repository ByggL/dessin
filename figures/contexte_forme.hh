#ifndef context_forme_h
#define context_forme_h

#include <string>
#include <map>
#include <vector>
#include <memory>

class Contexte_forme {
private:
    // Utilisation de variable :
    // C1 = carré 0 0 50 -> couleur : rouge & opacité : 30%
    std::map<std::string, sharedptr<forme>> variables;

    // Utilisation de l'indice dans l'ordre de création :
    // C[0], C[1], etc...
    std::vector<std::shared_ptr<forme>>     formes;
    std::vector<std::shared_ptr<rectangle>> rectangles;
    std::vector<std::shared_ptr<carre>>     carres;
    std::vector<std::shared_ptr<cercle>>    cercles;
    std::vector<std::shared_ptr<ellipse>>   ellipses;
    std::vector<std::shared_ptr<ligne>>     lignes;
    std::vector<std::shared_ptr<texte>>     textes;
    std::vector<std::shared_ptr<chemin>>    chemins;


public:
    Contexte_forme() = default;
    Contexte_forme(const Contexte_forme & autre) = default;

    std::shared_ptr<forme> get(const std::string & nom);
    const std::shared_ptr<forme> get(const std::string & nom) const;

    std::shared_ptr<forme> operator[](const std::string & nom);
    const std::shared_ptr<forme> operator[](const std::string & nom) const;


};


#endif
