%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"  // required by yacc output
%}

%%
[ \t\n]+                    ;  // Skip whitespace

[a-zA-Z_][a-zA-Z0-9_]*      {
                              yylval.str = strdup(yytext);
                              return ID;
                           }

.                           ;  // Ignore everything else
%%

int yywrap() {
    return 1;
}
