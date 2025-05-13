%{
#include "parser.tab.h"   // Token definitions from parser
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
%}

digit   [0-9]
letter  [a-zA-Z]
id      {letter}({letter}|{digit})*

%%

"int"           { return INT; }
"if"            { return IF; }
"else"          { return ELSE; }

{id}            { yylval.str = strdup(yytext); return ID; }
{digit}+        { yylval.num = atoi(yytext); return NUM; }

"="             { return ASSIGN; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MUL; }
"/"             { return DIV; }

";"             { return SEMI; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }

[ \t\n]+        ;  // skip whitespace

.               { printf("Unknown character: %s\n", yytext); }

%%
