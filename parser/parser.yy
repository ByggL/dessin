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


%token                  RECTANGLE
%token                  CARRE
%token                  TRIANGLE
%token                  CERCLE
%token                  ELLIPSE
%token                  LIGNE
%token                  CHEMIN
%token                  TEXTE

%token                  TAILLE

%token                  COULEUR
%token                  ROTATION
%token                  REMPLISSAGE
%token                  OPACITE
%token                  EPAISSEUR

%token                  COULEUR_HEX
%token                  COULEUR_RGB
%token                  COULEUR_NOM

%type <ExpressionPtr>   operation
%type <coordChemin>     coordonnee_chemin
%type <formePtr>        forme
/* %type <mapStrStr>       attributs */
/* %type <std::pair<std::string,std::string>>      attribut */
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
    | affectation {
    }
    | dessin {
    }
    /* | IF '(' operation ')' THEN '{' instruction '}' { */
    /*     $$ = std::make_shared<ExpressionTernaire>($3,$7,OperateurBinaire::ifthen) */
    /* } */
    /* | IF '(' operation ')' THEN '{' instruction '}' ELSE '{' instruction '}' { */
    /*     $$ = std::make_shared<ExpressionTernaire>($3,$7,$11,OperateurBinaire::ifthen) */
    /* } */

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
        std::cout << "Affectation à réaliser" << std::endl;
    }

dessin:
    TAILLE operation operation {
        driver.setCanevasLong($2->calculer(driver.getContexte()));
        driver.setCanevasHaut($3->calculer(driver.getContexte()));
    }
    |forme {
    }
    | forme attributs {
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
    }
    | CARRE operation operation operation {

        $$ = std::make_shared<Carre>(
        $2->calculer(driver.getContexte()),
        $3->calculer(driver.getContexte()),
        $4->calculer(driver.getContexte())
        );
        driver.ajoutCarre($$);

    }
    | TRIANGLE operation operation operation operation {
        $$ = std::make_shared<Triangle>(
            $2->calculer(driver.getContexte()),
            $3->calculer(driver.getContexte()),
            $4->calculer(driver.getContexte()),
            $5->calculer(driver.getContexte())
        );
    }
    | CERCLE operation operation operation {
        $$ = std::make_shared<Cercle>(
            $2->calculer(driver.getContexte()),
            $3->calculer(driver.getContexte()),
            $4->calculer(driver.getContexte())
        );
    }
    | ELLIPSE operation operation operation operation {
        $$ = std::make_shared<Ellipse>(
            $2->calculer(driver.getContexte()),
            $3->calculer(driver.getContexte()),
            $4->calculer(driver.getContexte()),
            $5->calculer(driver.getContexte())
        );
    }
    | LIGNE operation operation operation operation {
        $$ = std::make_shared<Ligne>(
            $2->calculer(driver.getContexte()),
            $3->calculer(driver.getContexte()),
            $4->calculer(driver.getContexte()),
            $5->calculer(driver.getContexte())
        );
    }
    | CHEMIN coordonnee_chemin {
        /* std::cout << "chemin" << std::endl; */
        $$ = std::make_shared<Chemin>($2);
    }
    | TEXTE operation operation CHAINE CHAINE {
        $$ = std::make_shared<Texte>(
            $2->calculer(driver.getContexte()),
            $3->calculer(driver.getContexte()),
            $4, $5
        );
    }

coordonnee_chemin:
    operation operation ',' coordonnee_chemin {
        /* std::cout << "op op , cood_chemin" << std::endl; */
        $$ = std::vector<int>();
        $$.push_back($1->calculer(driver.getContexte()));
        $$.push_back($2->calculer(driver.getContexte()));
    }
    |operation operation {
        /* std::cout << "op op " << std::endl; */
        $$.push_back($1->calculer(driver.getContexte()));
        $$.push_back($2->calculer(driver.getContexte()));
    }

attributs:
    forme FLECHE attribut ';'{
    }
    |forme '{' attribut '}' {
    }

attribut:
    COULEUR ':' CHAINE {
        //$$.addAttribut("stroke", std::make_shared<Couleur>($3)->_couleur);
    }
    |ROTATION ':' CHAINE {
        //std::ostringstream o;
        //o << "rotate(" << $3 << $$.centreX() << "," << $$.centreY() << ")"; // ajouter centre de la forme */
        //$$.addAttribut("transform", o.str());
    }
    |REMPLISSAGE ':' CHAINE {
        //$$.addAttribut("fill", std::make_shared<Couleur>($3)->_couleur);
    }
    |OPACITE ':' CHAINE {
        //$$.addAttribut("opacity", stoi($3.substr(0,2))/100);  // on transforme "50%" en 0.5 (par exemple) */
     }
    |EPAISSEUR ':' CHAINE {
/*         $$.addAttribut("stroke-width", $3); */
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
