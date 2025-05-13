%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>

int curr_line = 1;  // Global line number tracker
%}

%option noyywrap

DIGIT      [0-9]
LETTER     [a-zA-Z_]
ID         {LETTER}({LETTER}|{DIGIT})*

%%

"int"              { return INT; }
{ID}               { yylval.sval = strdup(yytext); return ID; }
{DIGIT}+           { yylval.ival = atoi(yytext); return NUMBER; }
"="                { return '='; }
"+"                { return '+'; }
"-"                { return '-'; }
"*"                { return '*'; }
"/"                { return '/'; }
";"                { return ';'; }
\n                 { curr_line++; }
[ \t\r]+           ; // Ignore spaces and tabs
.                  { return yytext[0]; }
