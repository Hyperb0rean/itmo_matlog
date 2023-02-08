%{
#include <string>
#include "../expression.h"
#include "expression.tab.h"
%}

%option outfile="lex.c" header-file="lex.h"


white [ \t\r]+
digit [0-9]
letter [A-Z]
symbol {letter}({letter}|{digit}|"'")*

%%
{symbol} {
    yylval.name=new std::string(yytext);
    return NAME;
}
"&" return AND;
"|" return OR;
"->" return IMP;
"!" return NEG;
"(" return LEFT;
")" return RIGHT;
"\n" return END;
%%
