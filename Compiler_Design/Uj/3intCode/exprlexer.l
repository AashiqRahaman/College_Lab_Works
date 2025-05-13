%{
#include "exprparser.tab.h"
%}

%option noyywrap

DIGIT      [0-9]
ID         [a-zA-Z_][a-zA-Z0-9_]*
WHITESPACE [ \t\n]+

%%

{WHITESPACE}           ; // skip whitespace

"="                    { return ASSIGN; }
";"                    { return SEMICOLON; }
"("                    { return LPAREN; }
")"                    { return RPAREN; }
"+"                    { return PLUS; }
"-"                    { return MINUS; }
"*"                    { return MUL; }
"/"                    { return DIV; }

{ID}                   { yylval.str = strdup(yytext); return ID; }
{DIGIT}+               { yylval.str = strdup(yytext); return NUM; }

.                      { /* ignore unknown characters */ }

%%
