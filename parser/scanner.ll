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
"." return '.';
"[" return '[';
"]" return ']';

"°"  {
    return token::DEGREE;
}

"->"  {
    return token::FLECHE;
}


(?i:rectangle) { return token::RECTANGLE; }

(?i:carr[e|é]) { return token::CARRE; }

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

(?i:opacit[e|é]) { return token::OPACITE; }

(?i:[e|é]paisseur) { return token::EPAISSEUR; }


"#"[0-9a-fA-F]{6}     {
    yylval->build<std::string>(YYText());
    return token::COULEUR_HEX;
}

"rgb"   {
    yylval->build<std::string>(YYText());
    return token::COULEUR_RGB;
}

(?i:rouge) {
    yylval->build<std::string>(YYText());
    return token::COULEUR_NOM;
}

(?i:vert) {
    yylval->build<std::string>(YYText());
    return token::COULEUR_NOM;
}

(?i:bleu) {
    yylval->build<std::string>(YYText());
    return token::COULEUR_NOM;
}

(?i:jaune) {
    yylval->build<std::string>(YYText());
    return token::COULEUR_NOM;
}

(?i:violet) {
    yylval->build<std::string>(YYText());
    return token::COULEUR_NOM;
}

(?i:magenta) {
    yylval->build<std::string>(YYText());
    return token::COULEUR_NOM;
}

(?i:cyan) {
    yylval->build<std::string>(YYText());
    return token::COULEUR_NOM;
}

(?i:noir) {
    yylval->build<std::string>(YYText());
    return token::COULEUR_NOM;
}

(?i:blanc) {
    yylval->build<std::string>(YYText());
    return token::COULEUR_NOM;
}

[a_zA-Z_][a-zA-Z_0-9]*   { // Identifiant
    yylval->build<std::string>(YYText());
    return token::IDENT;
}

(?:positionX) {
    return token::POSITIONX;
}

(?:positionY) {
    return token::POSITIONY;
}

(?i:bool[é|e]n) {
    return token::BOOLEAN;
}

(?i:entier) {
    return token::ENTIER;
}

(?i:r[é|e]l) {
    return token::REEL;
}

(?i:true) {
    yylval->build<bool>(1);
    return token::BOOL;
}

(?i:false) {
    yylval->build<int>(0);
    return token::BOOL;
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

[0-9]+     {
    yylval->build<int>(std::stod(YYText()));
    return token::NUMBER;
}

[0-9]+(\.[0-9]+)?     {
    yylval->build<float>(std::stod(YYText()));
    return token::FLOATNUMBER;
}


\"[^\"]+\" {
    yylval->build<std::string>(YYText());
    return token::CHAINE;
}


[ \t] {
}

^[ \t\n]+  { /* Ignore les lignes vides */
}

"\n"          {
    loc->lines();
    return token::NL;
}

<<EOF>> { /* token prédéfini pour la fin d'un fichier */
    return token::END_OF_FILE;
}


%%
