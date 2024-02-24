%skeleton "lalr1.cc"
%require "3.0"

%defines
%define api.parser.class { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
    #include "contexte.hh"
    #include "expressionBinaire.hh"
    #include "expressionUnaire.hh"
    #include "expressionTernaire.hh"
    #include "constante.hh"
    #include "variable.hh"
    #include "forme.hh"
    #include "carre.hh"
    #include "triangle.hh"
    #include "cercle.hh"
    #include "ellipse.hh"
    #include "texte.hh"
    #include "rectangle.hh"
    #include "ligne.hh"
    #include "chemin.hh"
    #include "contexte_forme.hh"
    #include "couleur.hh"
    #include "couleur_hex.hh"
    #include "couleur_nom.hh"
    #include "couleur_rgb.hh"
    #include "attribut.hh"
    #include "stroke.hh"
    #include "fill.hh"
    #include "rotation.hh"
    #include "epaisseur.hh"
    #include "opacite.hh"

    class Scanner;
    class Driver;
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code{
    #include <iostream>
    #include <string>
    #include <sstream>

    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex
}

%token                  NL
%token                  END
%token <int>            NUMBER
%token <std::string>    CHAINE
%token                  FLECHE
%token <std::string>    IDENT
%token                  IF
%token                  THEN
%token                  ELSE


%token                  RECTANGLE CARRE TRIANGLE CERCLE ELLIPSE LIGNE CHEMIN TEXTE

%token                  TAILLE

%token                  COULEUR
%token                  ROTATION
%token                  REMPLISSAGE
%token                  OPACITE
%token                  EPAISSEUR

%token <std::string>    COULEUR_HEX
%token <std::string>    COULEUR_RGB
%token <std::string>    COULEUR_NOM

%type <ExpressionPtr>   operation
%type <coordChemin>     coordonnee_chemin
%type <formePtr>        forme dessin
%type <vectAttributPtr> attributsFlc attributsCSS
%type <attributPtr>     attribut
%type <couleurPtr>      couleur
%left '-' '+'
%left '*' '/'

%%

programme:
    instruction NL programme
    | END NL {
        YYACCEPT;
    }

instruction:
    expression  {
    }
    | dessin {
    }
    | affectation {
    }

expression:
    operation {
        //Modifier cette partie pour prendre en compte la structure avec expressions
        try{
            std::cout << "#-> " << $1->calculer(driver.getContexte()) << std::endl;
        } catch (const std::exception& err){
            std::cerr << "#-> " << err.what() << std::endl;
        }
    }

affectation:
    IDENT '=' dessin {
        driver.ajoutFormeNomer($1,$3);
    }

dessin:
    TAILLE operation operation ';'{
        driver.setCanevasLong($2->calculer(driver.getContexte()));
        driver.setCanevasHaut($3->calculer(driver.getContexte()));
    }
    |forme ';' {
        $$ = $1;
    }
    | forme FLECHE attributsFlc ';' {
        std::cout << "forme fleche attributs" << std::endl;
        $1->_attributs = $3;
        $$ = $1;
    }
    | forme '{' attributsCSS '}' {
        $1->_attributs = $3;
        $$ = $1;
    }


forme:
    RECTANGLE operation operation operation operation operation operation operation operation {
        $$ = std::make_shared<Rectangle>(
            $2->calculer(driver.getContexte()),
            $3->calculer(driver.getContexte()),
            $4->calculer(driver.getContexte()),
            $5->calculer(driver.getContexte()),
            $6->calculer(driver.getContexte()),
            $7->calculer(driver.getContexte()),
            $8->calculer(driver.getContexte()),
            $9->calculer(driver.getContexte())
        );
        driver.ajoutRectangle($$);
        driver.ajoutForme($$);
    }
    | CARRE operation operation operation {
        $$ = std::make_shared<Carre>(
        $2->calculer(driver.getContexte()),
        $3->calculer(driver.getContexte()),
        $4->calculer(driver.getContexte())
        );
        driver.ajoutCarre($$);
        driver.ajoutForme($$);
        std::cout << "forme" << std::endl;
    }
    | TRIANGLE operation operation operation operation {
        $$ = std::make_shared<Triangle>(
            $2->calculer(driver.getContexte()),
            $3->calculer(driver.getContexte()),
            $4->calculer(driver.getContexte()),
            $5->calculer(driver.getContexte())
        );
        driver.ajoutTriangle($$);
        driver.ajoutForme($$);
    }
    | CERCLE operation operation operation {
        $$ = std::make_shared<Cercle>(
            $2->calculer(driver.getContexte()),
            $3->calculer(driver.getContexte()),
            $4->calculer(driver.getContexte())
        );
        driver.ajoutCercle($$);
        driver.ajoutForme($$);
    }
    | ELLIPSE operation operation operation operation {
        $$ = std::make_shared<Ellipse>(
            $2->calculer(driver.getContexte()),
            $3->calculer(driver.getContexte()),
            $4->calculer(driver.getContexte()),
            $5->calculer(driver.getContexte())
        );
        driver.ajoutEllipse($$);
        driver.ajoutForme($$);
    }
    | LIGNE operation operation operation operation {
        $$ = std::make_shared<Ligne>(
            $2->calculer(driver.getContexte()),
            $3->calculer(driver.getContexte()),
            $4->calculer(driver.getContexte()),
            $5->calculer(driver.getContexte())
        );
        driver.ajoutLigne($$);
        driver.ajoutForme($$);
    }
    | CHEMIN coordonnee_chemin {
        $$ = std::make_shared<Chemin>($2);
        driver.ajoutChemin($$);
        driver.ajoutForme($$);
    }
    | TEXTE operation operation CHAINE CHAINE {
        $$ = std::make_shared<Texte>(
            $2->calculer(driver.getContexte()),
            $3->calculer(driver.getContexte()),
            $4, $5
        );
        driver.ajoutTexte($$);
        driver.ajoutForme($$);
    }

coordonnee_chemin:
    operation operation ',' coordonnee_chemin {
        $$ = std::vector<int>();
        $$.push_back($1->calculer(driver.getContexte()));
        $$.push_back($2->calculer(driver.getContexte()));
        $$.insert($$.end(), $4.begin(), $4.end());
    }
    | operation operation {
        $$.push_back($1->calculer(driver.getContexte()));
        $$.push_back($2->calculer(driver.getContexte()));
    }


attributsFlc:
    attribut {
        std::cout << "Attribut fleche fin" << std::endl;
        $$.push_back($1);
    }
    | attribut '&' attributsFlc {
        std::cout << "Attribut fleche" << std::endl;
        $$.push_back($1);
        $$.insert($$.end(), $3.begin(), $3.end());
    }

attributsCSS:
    attribut ';' {
        $$.push_back($1);
    }
    | attribut ';' NL attributsCSS {
        $$.push_back($1);
        $$.insert($$.end(), $4.begin(), $4.end());
    }


attribut:
    COULEUR ':' couleur {
        std::cout << "couleur" << std::endl;
        $$ = std::make_shared<Stroke>(*$3);
    }
    | REMPLISSAGE ':' couleur {
        std::cout << "remplissage" << std::endl;
        $$ = std::make_shared<Fill>(*$3);
    }
    | ROTATION ':' NUMBER {
        std::cout << "rotation" << std::endl;
        $$ = std::make_shared<Rotation>($3);
    }
    | OPACITE ':' NUMBER {
        std::cout << "opacite" << std::endl;
        $$ = std::make_shared<Opacite>($3);
    }
    | EPAISSEUR ':' NUMBER {
        std::cout << "epaisseur" << std::endl;
        $$ = std::make_shared<Epaisseur>($3);
    }


couleur:
    COULEUR_RGB '(' NUMBER ',' NUMBER ',' NUMBER ')' {
        std::cout << $3 << " " << $5 << " " << $7 << std::endl;
        $$ = std::make_shared<Couleur_rgb>($3, $5, $7);
    }
    | COULEUR_NOM  {
        $$ = std::make_shared<Couleur_nom>($1);
    }
    | COULEUR_HEX {
        $$ = std::make_shared<Couleur_hex>($1);
    }


operation:
    NUMBER {
        $$ = std::make_shared<Constante>($1);
    }
    | '(' operation ')' {
        $$ = $2;
    }
    | operation '+' operation {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::plus);
    }
    | operation '-' operation {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::moins);
    }
    | operation '*' operation {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::multiplie);
    }
    | operation '/' operation {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::divise);
    }

%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
