%{
#include<stdio.h>
%}

%option noyywrap

KEYWORDS (auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while)
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*

%%
{KEYWORDS} { printf("Keyword: %s\n", yytext); }
{IDENTIFIER} { printf("Identifier: %s\n", yytext); }
. ;
%%

int main(int argc, char *argv[]) {
    if(argc > 1) {
        yyin = fopen(argv[1], "r");
        if(yyin == NULL) {
            printf("Cannot open file: %s\n", argv[1]);
            return 1;
        }
    }
    yylex();
    fclose(yyin);
    return 0;
}

/* To compile and run the lex program:

1. Save the above code in a file named `lex.l`.
2. Open a terminal or command prompt and navigate to the directory where the `lex.l` file is located.
3. Run the following commands:
   - `lex lex.l` to generate the lexical analyzer (`lex.yy.c`).
   - `gcc lex.yy.c -o lex_program -lfl` to compile the lexical analyzer into an executable named `lex_program`.
   - `./lex_program input.c` to run the lexical analyzer on the input C program (`input.c`). Replace `input.c` with the path to your C program file.

The lex program will output the identified keywords and identifiers in the input C program.  */