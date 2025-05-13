%{
#include "parser.tab.h"  // Include the parser's header for token definitions
%}

%%

[ \t\n]         ;  // Ignore whitespace (spaces, tabs, newlines)
[0-9]+          { yylval.num = atoi(yytext); return NUMBER; }  // Match integers
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return ID; }  // Match identifiers
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MUL; }
"/"             { return DIV; }
.               { return yytext[0]; }  // Return any other character as-is (e.g., for error handling)

%%

int yywrap() {
    return 1;  // Indicate end of input
}