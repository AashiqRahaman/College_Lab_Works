%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void yyerror(const char *s);
%}

%option noyywrap

DIGIT     [0-9]
LETTER    [a-zA-Z_]
ID        {LETTER}({LETTER}|{DIGIT})*
INT_LIT   {DIGIT}+
STR_LIT   \"([^\"\\]|\\.)*\"
WS        [ \t\n]+
COMMENT   ("//".*|"/\\*"([^*]|"*"[^/])*"\\*/")

%%

"int"       { return INT; }
"char"      { return CHAR; }
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"return"    { return RETURN; }
"void"      { return VOID; }

"=="        { return EQ; }
"!="        { return NE; }

"{"         { return '{'; }
"}"         { return '}'; }
"("         { return '('; }
")"         { return ')'; }
";"         { return ';'; }
","         { return ','; }
"="         { return '='; }
"<"         { return '<'; }
">"         { return '>'; }
"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }

{INT_LIT}   { yylval.int_val = atoi(yytext); return INT_LIT; }
{STR_LIT}   { yylval.str_val = strdup(yytext); return STR_LIT; }
{ID}        { yylval.id = strdup(yytext); return ID; }
{WS}        { /* skip whitespace */ }
{COMMENT}   { /* skip comments */ }

.           { yyerror("Invalid character"); }

%%
