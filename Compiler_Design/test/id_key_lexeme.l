%{
#include <stdio.h>
%}

%option noyywrap

DIGIT    [0-9]
LETTER   [a-zA-Z_]
ID       {LETTER}({LETTER}|{DIGIT})*
WHITESPACE [ \t\n\r]+

%%

"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"    { printf("Keyword: %s\n", yytext); }

{ID}                                    { printf("Identifier: %s\n", yytext); }

{DIGIT}+                                { /* Ignore integers */ }
{DIGIT}*\.{DIGIT}+                      { /* Ignore floats */ }
"\""[^\"]*"\""                          { /* Ignore strings */ }
"'"[^']"'"                              { /* Ignore characters */ }
"//".*                                  { /* Ignore single-line comments */ }
"/*"([^*]|\*+[^*/])*\*+"/"             { /* Ignore multi-line comments */ }
[+\-*/=<>!&|%^~]                        { /* Ignore operators */ }
[{}[\]().,;]                            { /* Ignore punctuation */ }
{WHITESPACE}                            { /* Ignore whitespace */ }
.                                       { /* Ignore anything else */ }

%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <c_file>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }
    yyin = file;
    yylex();
    fclose(file);
    return 0;
}