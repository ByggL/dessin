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
"%" return '%';


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

(?i:texte) { return token::TEXTE; }


(?i:couleur) { return token::COULEUR; }

(?i:rotation) { return token::ROTATION; }

(?i:remplissage) { return token::REMPLISSAGE; }

(?i:opacite) { return token::OPACITE; }

(?i:epaisseur) { return token::EPAISSEUR; }


"#"([0-9A-F]{2}){3}     {
    return token::COULEUR_HEX;
}

"rgb"   {
    return token::COULEUR_RGB;
}

(?i:rouge) { return token::COULEUR_NOM; }

(?i:vert) { return token::COULEUR_NOM; }

(?i:bleu) { return token::COULEUR_NOM; }

(?i:jaune) { return token::COULEUR_NOM; }

(?i:violet) { return token::COULEUR_NOM; }

(?i:magenta) { return token::COULEUR_NOM; }

(?i:cyan) { return token::COULEUR_NOM; }

(?i:noir) { return token::COULEUR_NOM; }

(?i:blanc) { return token::COULEUR_NOM; }


[0-9]+      {
    yylval->build<int>(std::atoi(YYText()));
    return token::NUMBER;
}

[A-Z][a-z]*[0-9]+   {
    yylval->build<std::string>(YYText());
    return token::IDENT;
}

\"[a-zA-Z0-9 ]+\" {
    yylval->build<std::string>(YYText());
    return token::CHAINE;
}


[ \t] {
}

"\n"          {
    loc->lines();
    return token::NL;
}

%%
