%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int curr_line;
int tempCount = 0;

char* newTemp();
void yyerror(const char *s);
int yylex();
%}

%union {
    int ival;
    char* sval;
}

%token <sval> ID
%token <ival> NUMBER
%token INT
%type <sval> expr assign

%%

program:
    program stmt
  | stmt
  ;

stmt:
    decl ';'
  | assign ';' {
        printf("Line %d: %s\n", curr_line, $1);
        free($1);
    }
  ;

decl:
    INT ID {
        printf("Line %d: Declare: %s\n", curr_line, $2);
        free($2);
    }
  ;

assign:
    ID '=' expr {
        char *code = malloc(100);
        sprintf(code, "%s = %s", $1, $3);
        free($3);
        $$ = code;
        free($1);
    }
  ;

expr:
    expr '+' expr {
        char *tmp = newTemp();
        printf("Line %d: %s = %s + %s\n", curr_line, tmp, $1, $3);
        free($1); free($3);
        $$ = tmp;
    }
  | expr '-' expr {
        char *tmp = newTemp();
        printf("Line %d: %s = %s - %s\n", curr_line, tmp, $1, $3);
        free($1); free($3);
        $$ = tmp;
    }
  | expr '*' expr {
        char *tmp = newTemp();
        printf("Line %d: %s = %s * %s\n", curr_line, tmp, $1, $3);
        free($1); free($3);
        $$ = tmp;
    }
  | expr '/' expr {
        char *tmp = newTemp();
        printf("Line %d: %s = %s / %s\n", curr_line, tmp, $1, $3);
        free($1); free($3);
        $$ = tmp;
    }
  | NUMBER {
        char *val = malloc(20);
        sprintf(val, "%d", $1);
        $$ = val;
    }
  | ID {
        $$ = strdup($1);
        free($1);
    }
  ;

%%

char* newTemp() {
    char *temp = malloc(10);
    sprintf(temp, "t%d", tempCount++);
    return temp;
}

void yyerror(const char *s) {
    fprintf(stderr, "Line %d: syntax error: %s\n", curr_line, s);
}
