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

"rectangle" return token::RECTANGLE;
"carré" return token::CARRE;
"triangle" return token::TRIANGLE;
"cercle" return token::CERCLE;
"ellipse" return token::ELLIPSE;
"ligne" return token::LIGNE;
"chemin" return token::CHEMIN;
"texte" return token::TEXTE;

"taille" return token::SIZE;

"+" return '+';
"*" return '*';
"-" return '-';
"/" return '/';
"(" return '(';
")" return ')';
"=" return '=';

(?i:si) {
    return token::SI;
}

(?i:alors) {
    return token::ALORS;
}

(?i:sinon) {
    return token::SINON;
}

"tant que" {
    return token::WHILE;
}

"=="|"est" {
    return token::EGAL;
}

"!="|"n'est pas" {
    return token::DIFFERENT;
}

">=" {
    return token::GREATEREQ;
}

">" {
    return token::GREATER;
}

"<=" {
    return token::LESSEREQ;
}

"<" {
    return token::LESSER;
}

[0-9]+      {
    yylval->build<int>(std::atoi(YYText()));
    return token::NUMBER;
}

"\n"          {
    loc->lines();
    return token::NL;
}

[a-zA-Z]+   {
    yylval->build<std::string>(std::atoi(YYText()));
    return token::STRING;
}

%%
