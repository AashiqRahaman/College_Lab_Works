%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tempCount = 1;

char* newTemp() {
    static char temp[20];
    sprintf(temp, "t%d", tempCount++);
    return strdup(temp);
}

void yyerror(const char *s);
int yylex(void);
%}

%union {
    char *str;
    struct {
        char *place;
    } expr;
}

%token <str> ID NUM
%token ASSIGN SEMICOLON LPAREN RPAREN PLUS MINUS MUL DIV

%type <expr> expr term factor

%%

program:
    /* empty */
    | program stmt
    ;

stmt:
    ID ASSIGN expr SEMICOLON {
        printf("%s = %s\n", $1, $3.place);
        free($1);
        free($3.place);
    }
    ;

expr:
    expr PLUS term {
        char *temp = newTemp();
        printf("%s = %s + %s\n", temp, $1.place, $3.place);
        free($1.place);
        free($3.place);
        $$ .place = temp;
    }
    | expr MINUS term {
        char *temp = newTemp();
        printf("%s = %s - %s\n", temp, $1.place, $3.place);
        free($1.place);
        free($3.place);
        $$ .place = temp;
    }
    | term {
        $$ = $1;
    }
    ;

term:
    term MUL factor {
        char *temp = newTemp();
        printf("%s = %s * %s\n", temp, $1.place, $3.place);
        free($1.place);
        free($3.place);
        $$ .place = temp;
    }
    | term DIV factor {
        char *temp = newTemp();
        printf("%s = %s / %s\n", temp, $1.place, $3.place);
        free($1.place);
        free($3.place);
        $$ .place = temp;
    }
    | factor {
        $$ = $1;
    }
    ;

factor:
    LPAREN expr RPAREN {
        $$ = $2;
    }
    | ID {
        $$ .place = $1;
    }
    | NUM {
        $$ .place = $1;
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input.c>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("Failed to open input file");
        return 1;
    }

    extern FILE *yyin;
    yyin = f;

    printf("Intermediate Code:\n\n");
    yyparse();

    fclose(f);
    return 0;
}
