# Projet dessin

```
├── attributs/          // classes d'attributs
├── couleur/            // classes de gestion des couleurs
├── exemples/           // exemples tirés du sujet pour tests
├── expressions/        // classes d'expressions logiques et arithmétiques
├── figures/            // classes de gestion de figures
├── parser/             // gestion de la grammaire
│
├── .gitignore
├── CMakeLists.txt
└── README.md
```

## Figures

Chaque type de figure possède sa propre classe. 
Elles descendent toutes de la classe Forme, qui contient aussi une liste d'attributs.

Les figures dont on renseigne les coordonnées de départ suivi d'une ou plusieurs variables de taille descendent de la classe FormeSimpleCoord.
Les autres figures qui ne descendent pas de FormeSimpleCoord sont Rectangle (qui prend les coordonnées de chaque coin), Ligne (qui prend les coordonnées de ses deux extrémités) et Chemin (qui prend un nombre indéfini de coordonnées). 

En SVG, les rectangles sont définis par les coordonnées d'un coin, de sa largeur et de sa hauteur. Il n'a donc pas été nécessaire d'utiliser les 8 valeurs de coordonnées, seulement celles utiles pour calculer la largeur et la hauteur. (Note : d'après les exemples du sujet, on part du principe qu'un rectangle est forcément un rectangle et non pas un quadrilatère qui n'est pas nécessairement un rectangle) 

### Méthodes notables

- `to_string()` retourne une std::string décrivant la figure au format SVG
- `centreX()` et `centreY()` retournent les coordonnées considérées comme le "centre" de la figure. Ces méthodes sont nécessaires pour écrire l'instruction de rotation au format SVG.

- `toSVG()` retourne un std::string décrivant la figure complète, incluant les attributs avec l'usage de `type()` et `valeur()` (voir plus bas), avec des valeurs d'attributs par défaut pour la couleur et le remplissage si ceux-ci ne sont pas renseignés. Cette fonction est exclusive à la classe Forme.

### Contexte_forme

La classe Contexte_forme est l'équivalent de la classe Contexte pour les formes. C'est en quelque sorte le canevas du dessin.
La totalité des formes du dessin sont contenues dans le vecteur `forme`, et en fonction de quelle forme il s'agit ou de si elles sont des variables, elles sont également ajoutées aux variable respectives pour pouvoir y accéder tel que dans l'exemple 3.

La méthode `toSVG()` crée un std::string contenant le SVG complet.
La méthode `writeToSvgFile()` écrit la std::string passée en paramètre (en l'occurence celle issue de `toSVG()`) dans le fichier `output.svg`.

## Attributs

Chaque attribut possède sa propre classe et descend de la classe Attribut.
Les attributs ayant une couleur comme valeur descendent d'AttributCouleur. Les attributs ayant une valeur numérique descendent d'AttributInt.
Lorsque un attribut est ajouté à une figure, une instance de cet attribut est créée et est ajouté au std::vector _attribut de la forme liée.
Chaque attribut possède les méthodes `type()` et `valeur()` retournant son type et sa valeur pour la conversion au format SVG.

## Couleurs

Les couleurs sont gérées par leur propre ensemble de classes permettant de créer une couleur en fonction de si elle est renseignée au format RGB, hexadécimal, ou nommé.

Par soucis de standardisation, les couleurs sont toutes formatées au format hexadécimal lors de leurs créations.

## Expressions

La gestion des expressions logiques et mathématiques est essentiellement tirée du TP3 de calculatrice.

[ajouter ici détails sur boucles et fonctions si applicable]


# Ce qui fonctionne ou pas

## Ce qui fonctionne

- la création de formes (exemple 1)
- la gestion des attributs et des couleurs (exemple 2)
- ajouter ce qui s'applique...

## Ce qui ne fonctionne pas

- y mettre ce qui s'applique

## Erreurs et problèmes rencontrés

- y mettre ce qui s'applique

# Barème et todo

-   Gestion des figures simples : 5 points ✅
-   Gestion des attributs : 3 points ✅
-   Gestion des couleurs : 2 points ✅
-   Gestion des variables : 2 points
-   Gestion des conditionnelles : 2 points ✅
-   Gestion des boucles : 2 points
-   Gestion des fonctions : 2 points
-   Gestion de la sortie au format .svg : 2 points ✅
-   Propreté du code : 2 points


# PS

Les exemples utilisés sont ceux du sujet.