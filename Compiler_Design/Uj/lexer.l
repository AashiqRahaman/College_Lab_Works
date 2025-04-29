%{
#include "parcer.tab.h"
#include <stdlib.h>
#include <string.h>
%}

%%

[ \t\r\n]+              ;  // Skip whitespace

"int"                   { return INT; }
[0-9]+                  { yylval.ival = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.sval = strdup(yytext); return ID; }

"="                     return '=';
";"                     return ';';
"("                     return '(';
")"                     return ')';
"+"                     return '+';
"-"                     return '-';
"*"                     return '*';
"/"                     return '/';
"%"                     return '%';

.                       { printf("Unknown character: %s\n", yytext); return -1; }

%%
