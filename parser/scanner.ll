%{

#include "scanner.hh"
#include <cstdlib>

#define YY_NO_UNISTD_H

using token = yy::Parser::token;

#undef  YY_DECL
#define YY_DECL int Scanner::yylex( yy::Parser::semantic_type * const lval, yy::Parser::location_type *loc )

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option c++
%option yyclass="Scanner"
%option noyywrap

%%
%{
    yylval = lval;
%}
fin return token::END;

"+" return '+';
"*" return '*';
"-" return '-';
"/" return '/';
"(" return '(';
")" return ')';
"=" return '=';
"," return ',';
":" return ':';
"&" return '&';
"{" return '{';
"}" return '}';
";" return ';';


"->"  {
    return token::FLECHE;
}

"si" {
    return token::IF;
}
"alors" {
    return token::THEN;
}
"sinon" {
    return token::ELSE;
}

(?i:rectangle) { return token::RECTANGLE; }

(?i:carre) { return token::CARRE; }

(?i:triangle) { return token::TRIANGLE; }

(?i:cercle) { return token::CERCLE; }

(?i:ellipse) { return token::ELLIPSE; }

(?i:ligne) { return token::LIGNE; }

(?i:chemin) { return token::CHEMIN; }

(?i:taille) { return token::TAILLE; }

(?i:couleur) { return token::COULEUR; }

(?i:rotation) { return token::ROTATION; }

(?i:remplissage) { return token::REMPLISSAGE; }

(?i:opacite) { return token::OPACITE; }

(?i:epaisseur) { return token::EPAISSEUR; }

[0-9]+      {
    yylval->build<int>(std::atoi(YYText()));
    return token::NUMBER;
}

[a-zA-Z]+      {
    yylval->build<std::string>(YYText());
    return token::CHAINE;
}

\"[a-zA-Z]+[ ]?\" {
    yylval->build<std::string>(YYText());
    return token::TEXTECHAINE;
}


[ \t] {
}

"\n"          {
    loc->lines();
    return token::NL;
}

%%
