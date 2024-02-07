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
    #include "constante.hh"
    #include "variable.hh"

    class Scanner;
    class Driver;
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code{
    #include <iostream>
    #include <string>

    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex
}

%token                  NL
%token                  END
%token <int>            NUMBER
%token <std::string>         CHAINE
%token                  FLECHE

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

%type <ExpressionPtr>   operation
/* %type <figurePtr>       figure */
/* %type <formePtr>        forme */
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

expression:
    operation {
        //Modifier cette partie pour prendre en compte la structure avec expressions
        try{
            std::cout << "#-> " << $1->calculer(driver.getContexte()) << std::endl;
        } catch (const std::exception& err){
            std::cerr << "#-> " << err.what() << std::endl;
        }
    }
    | figure {

    }
    /* |forme { */
    /*  */
    /* } */

affectation:
    '=' {
        std::cout << "Affectation à réaliser" << std::endl;
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


coordonnee_chemin:
    operation operation ',' coordonnee_chemin {
        $$->ajout(std::make_shared<point>($1,$2));
    }
    operation operation {
        $$ = std::vector<point>();
        $$->ajout(std::make_shared<point>($1,$2));
    }

figure:
     RECTANGLE operation operation operation operation operation operation operation operation {
        $$ = std::make_shared<Rectangle>($2,$3,$4,$5,$6,$7,$8,$9);
    }
    | CARRE operation operation operation {
        $$ = std::make_shared<Carre>($2,$3,$4);
    }
    | TRIANGLE operation operation operation operation {
        $$ = std::make_shared<Triangle>($2,$3,$4,$5);
    }
    | CERCLE operation operation operation {
        $$ = std::make_shared<Cercle>($2,$3,$4);
    }
    | ELLIPSE operation operation operation operation {
        $$ = std::make_shared<Ellipse>($2,$3,$4,$5);
    }
    | LIGNE operation operation operation operation {
        $$ = std::make_shared<Ligne>($2,$3,$4,$5);
    }
    | CHEMIN coordonnee_chemin {
        $$ = std::make_shared<Chemin>($2);
    }
    | TEXTE operation operation CHAINE CHAINE {
        $$ = std::make_shared<Texte>($2,$3,$4,$5);
    }

/* attribut: */
/*     COULEUR ':' CHAINE { */
/*  */
/*     } */
/*     |ROTATION ':' CHAINE { */
/*  */
/*     } */
/*     |REMPLISSAGE ':' CHAINE { */
/*  */
/*     } */
/*     |OPACITE ':' CHAINE { */
/*  */
/*     } */
/*     |EPAISSEUR ':' CHAINE { */
/*  */
/*     } */
/*     |attribut '&' attribut { */
/*  */
/*     } */
/*     |attribut NL attribut { */
/*  */
/*     } */
/*  */
/* forme: */
/*      TAILLE operation operation { */
/*  */
/*      } */
/*      |figure FLECHE attribut { */
/*  */
/*      } */
/*      |figure '{' attribut '}' { */
/*  */
/*      } */



%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
