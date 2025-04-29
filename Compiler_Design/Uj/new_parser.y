%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARS 100

int flag = 0;

typedef struct {
    char name[32];
    int value;
} Variable;

Variable symtab[MAX_VARS];
int var_count = 0;

int yylex(void);          // Declare yylex function
void yyerror(const char *s);  // Declare yyerror function

int get_value(char* name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(symtab[i].name, name) == 0)
            return symtab[i].value;
    }
    printf("Error: Undefined variable %s\n", name);
    exit(1);
}

void set_value(char* name, int value) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(symtab[i].name, name) == 0) {
            symtab[i].value = value;
            return;
        }
    }
    strcpy(symtab[var_count].name, name);
    symtab[var_count].value = value;
    var_count++;
}
%}

%union {
    int ival;
    char* sval;
}

%token <sval> ID
%token <ival> NUMBER
%token INT

%left '+' '-'
%left '*' '/' '%'
%type <ival> expr

%%

program:
      statements
    ;

statements:
      statements statement
    | statement
    ;

statement:
      INT ID '=' expr ';'     { set_value($2, $4); printf("%s = %d\n", $2, $4); }
    | INT ID ';'              { set_value($2, 0); printf("%s = 0\n", $2); }
    ;

expr:
      expr '+' expr           { $$ = $1 + $3; }
    | expr '-' expr           { $$ = $1 - $3; }
    | expr '*' expr           { $$ = $1 * $3; }
    | expr '/' expr           { $$ = $1 / $3; }
    | expr '%' expr           { $$ = $1 % $3; }
    | '(' expr ')'            { $$ = $2; }
    | NUMBER                  { $$ = $1; }
    | ID                      { $$ = get_value($1); }
    ;

%%

int main() {
    printf("Enter C-like code:\n\n");
    yyparse();
    if (flag == 0)
        printf("\nAll expressions were valid.\n");
    return 0;
}

void yyerror(const char *s) {
    printf("Syntax error: %s\n", s);
    flag = 1;
}
