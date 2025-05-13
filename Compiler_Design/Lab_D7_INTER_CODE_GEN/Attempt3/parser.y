%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tempCount = 0;

typedef struct {
    char place[20];
} Expr;

char *newTemp();
void emit(char *code);
void yyerror(const char *s);
%}

%union {
    int num;
    char *str;
    Expr expr;
}

%token <str> ID
%token <num> NUM
%token INT IF ELSE
%token ASSIGN PLUS MINUS MUL DIV
%token SEMI LPAREN RPAREN LBRACE RBRACE

%type <expr> expr stmt

%left PLUS MINUS
%left MUL DIV

%%

program:
    decls stmts
;

decls:
    /* empty */
    | decls decl
;

decl:
    INT ID SEMI {
        printf("Declare variable %s\n", $2);
    }
;

stmts:
    /* empty */
    | stmts stmt
;

stmt:
    ID ASSIGN expr SEMI {
        char code[100];
        sprintf(code, "%s = %s", $1, $3.place);
        emit(code);
    }
    | IF LPAREN expr RPAREN stmt {
        // No code generation for if in this example
    }
    | '{' stmts '}'
;

expr:
    expr PLUS expr {
        char *temp = newTemp();
        char code[100];
        sprintf(code, "%s = %s + %s", temp, $1.place, $3.place);
        emit(code);
        strcpy($$.place, temp);
    }
    | expr MINUS expr {
        char *temp = newTemp();
        char code[100];
        sprintf(code, "%s = %s - %s", temp, $1.place, $3.place);
        emit(code);
        strcpy($$.place, temp);
    }
    | expr MUL expr {
        char *temp = newTemp();
        char code[100];
        sprintf(code, "%s = %s * %s", temp, $1.place, $3.place);
        emit(code);
        strcpy($$.place, temp);
    }
    | expr DIV expr {
        char *temp = newTemp();
        char code[100];
        sprintf(code, "%s = %s / %s", temp, $1.place, $3.place);
        emit(code);
        strcpy($$.place, temp);
    }
    | LPAREN expr RPAREN {
        strcpy($$.place, $2.place);
    }
    | ID {
        strcpy($$.place, $1);
    }
    | NUM {
        char numStr[20];
        sprintf(numStr, "%d", $1);
        strcpy($$.place, numStr);
    }
;

%%

char *newTemp() {
    static char tempName[20];
    sprintf(tempName, "t%d", tempCount++);
    return strdup(tempName);
}

void emit(char *code) {
    printf("%s\n", code);
}

int main() {
    printf("Enter your code:\n");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}
