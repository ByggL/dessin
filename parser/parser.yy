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
    #include "rectangle.hh"

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
%token <std::string>    STRING
%token                  SI
%token                  ALORS
%token                  SINON
%token                  WHILE

%token                  EGAL
%token                  DIFF
%token                  GREATEREQ
%token                  GREATER
%token                  LESSEREQ
%token                  LESSER

%token                  RECTANGLE
%token                  CARRE
%token                  TRIANGLE
%token                  CERCLE
%token                  ELLIPSE
%token                  LIGNE
%token                  CHEMIN
%token                  TEXTE
%token                  SIZE

%type <ExpressionPtr>   operation
%type <Forme>           forme
%type <ExpressionPtr>   comparaison
%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:
    instruction NL programme
    | END NL {
        YYACCEPT;
    }

instruction:
    expression  {
        YYACCEPT;
    }
    | affectation {
      YYACCEPT;
    }

expression:
    operation {
        try{
        std::cout << "#-> " << $1->calculer(driver.getContexte()) << std::endl;
        } catch (const std::exception& err){
            std::cerr << "#-> " << err.what() << std::endl;
        }
    }

    forme {

    }

affectation:
    '=' { std::cout << "Affectation à réaliser" << std::endl;
    }

operation:
    NUMBER {
        $$ = $1;
    }
    | SI '(' comparaison ')' ALORS operation SINON operation {
        $$ = std::make_shared<ExpressionTernaire>($3,$6,$8,OperateurTernaire::ifthenelse);
    }
    | '(' operation ')' {
        $$ = $2;
    }
    | operation '+' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::plus);
    }
    | operation '-' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::moins);
    }
    | operation '*' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::multiplie);
    }
    | operation '/' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::divise);
    }
    | '-' operation %prec NEG {
        $$ = std::make_shared<ExpressionUnaire>($2,OperateurUnaire::neg);
    }

comparaison:
    operation EGAL operation {
        $$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::egal);
    }
    | operation DIFF operation {
        $$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::different);        
    }
    | operation GREATEREQ operation {
        $$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::greatereq);        
    }
    | operation GREATER operation {
        $$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::greater);        
    }
    | operation LESSEREQ operation {
        $$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::lessereq);        
    }
    | operation LESSER operation {
        $$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::lesser);        
    }

forme:
    RECTANGLE NUMBER NUMBER NUMBER NUMBER NUMBER NUMBER NUMBER NUMBER { 
        $$ = std::make_shared<Rectangle>($2,$3,$4,$5,$6,$7,$8,$9);
    }
    | CARRE NUMBER NUMBER NUMBER {
        $$ = std::make_shared<Carre>($2,$3,$4);
    }
    | TRIANGLE NUMBER NUMBER NUMBER NUMBER {
        $$ = std::make_shared<Triangle>($2,$3,$4,$5);
    }
    | CERCLE NUMBER NUMBER NUMBER {
        $$ = std::make_shared<Cercle>($2,$3,$4);
    }
    | ELLIPSE NUMBER NUMBER NUMBER NUMBER {
        $$ = std::make_shared<Ellipse>($2,$3,$4,$5);
    }
    | RECTANGLE NUMBER NUMBER NUMBER NUMBER { 
        $$ = std::make_shared<Ligne>($2,$3,$4,$5);
    }
    | TEXTE NUMBER NUMBER '"'STRING'"' '"'STRING'"' {
        $$ = std::make_shared<Texte>($2,$3,$4,$5);
    }
    // chemin et texte à faire
%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
