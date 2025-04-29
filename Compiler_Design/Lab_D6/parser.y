%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
void yyerror(const char *s);
%}

%union {
    int int_val;
    char *str_val;
    char *id;
}

%token INT CHAR IF ELSE WHILE RETURN VOID
%token <int_val> INT_LIT
%token <str_val> STR_LIT
%token <id> ID
%token EQ NE

%right '='
%left EQ NE
%left '<' '>'
%left '+' '-'
%left '*' '/'

%type <id> parameter_declaration

%start program

%%

program:
      external_declaration
    | program external_declaration
    ;

external_declaration:
      type_specifier ID '(' parameter_list ')' compound_statement
        { printf("Function: %s (with parameters)\n", $2); }
    | type_specifier ID '(' ')' compound_statement
        { printf("Function: %s (no parameters)\n", $2); }
    ;

parameter_list:
      parameter_declaration
    | parameter_list ',' parameter_declaration
    ;

parameter_declaration:
    type_specifier ID { $$ = $2; }
    ;

type_specifier:
      INT   { printf("Type: int\n"); }
    | CHAR  { printf("Type: char\n"); }
    | VOID  { printf("Type: void\n"); }
    ;

compound_statement:
      '{' '}' 
        { printf("Empty block\n"); }
    | '{' statement_list '}' 
        { printf("Block with statements\n"); }
    | '{' declaration_list statement_list '}' 
        { printf("Block with declarations & statements\n"); }
    ;

declaration_list:
      declaration
    | declaration_list declaration
    ;

declaration:
      type_specifier ID ';' 
        { printf("Declared variable: %s\n", $2); }
    | type_specifier ID '=' expression ';'
        { printf("Declared & initialized: %s = ...\n", $2); }
    ;

statement_list:
      statement
    | statement_list statement
    ;

statement:
      expression_statement
    | compound_statement
    | if_statement
    | while_statement
    | return_statement
    ;

expression_statement:
      expression ';' 
        { printf("Expression evaluated\n"); }
    | ';' 
        { printf("Empty statement\n"); }
    ;

if_statement:
      IF '(' expression ')' statement 
        { printf("If-then\n"); }
    | IF '(' expression ')' statement ELSE statement 
        { printf("If-else\n"); }
    ;

while_statement:
      WHILE '(' expression ')' statement 
        { printf("While loop\n"); }
    ;

return_statement:
      RETURN expression ';' 
        { printf("Return with value\n"); }
    | RETURN ';' 
        { printf("Return void\n"); }
    ;

expression:
      ID '=' expression 
        { printf("Assignment: %s = ...\n", $1); }
    | expression EQ expression 
        { printf("Equality check\n"); }
    | expression NE expression 
        { printf("Inequality check\n"); }
    | expression '<' expression 
        { printf("Less-than\n"); }
    | expression '>' expression 
        { printf("Greater-than\n"); }
    | expression '+' expression 
        { printf("Addition\n"); }
    | expression '-' expression 
        { printf("Subtraction\n"); }
    | expression '*' expression 
        { printf("Multiplication\n"); }
    | expression '/' expression 
        { printf("Division\n"); }
    | '(' expression ')' 
        { printf("Parenthesized expression\n"); }
    | ID 
        { printf("Variable: %s\n", $1); }
    | INT_LIT 
        { printf("Integer: %d\n", $1); }
    | STR_LIT 
        { printf("String: %s\n", $1); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    exit(1);
}

int main() {
    printf("Starting C Parser...\n");
    yyparse();
    printf("Parsing completed.\n");
    return 0;
}
