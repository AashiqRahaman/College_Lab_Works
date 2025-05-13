%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
void yyerror(const char *s);

// Structure to hold intermediate code
typedef struct {
    char *code;  // The intermediate code string
} Node;

Node* create_node(char *code) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->code = strdup(code);
    return n;
}

// Temporary variable counter for intermediate code
int temp_count = 0;

// Generate intermediate code for binary operations
Node* generate_code(char *left, char *right, char op) {
    char buf[256];
    char temp[10];
    sprintf(temp, "t%d", temp_count++);  // e.g., t0, t1, t2
    sprintf(buf, "%s = %s %c %s", temp, left, op, right);
    printf("%s\n", buf);  // Print the intermediate code
    return create_node(temp);
}

%}

%union {
    int num;      // For numbers
    char *str;    // For identifiers
    Node *node;   // For AST nodes with intermediate code
}

%token <num> NUMBER
%token <str> ID
%token PLUS MINUS MUL DIV

%type <node> expr term factor

%left PLUS MINUS   // Precedence: + and - (left associative)
%left MUL DIV      // Precedence: * and / (higher than + and -, left associative)

%%

program: expr { printf("Parsing complete.\n"); }
       ;

expr: term                  { $$ = $1; }
    | expr PLUS term        { $$ = generate_code($1->code, $3->code, '+'); }
    | expr MINUS term       { $$ = generate_code($1->code, $3->code, '-'); }
    ;

term: factor                { $$ = $1; }
    | term MUL factor       { $$ = generate_code($1->code, $3->code, '*'); }
    | term DIV factor       { $$ = generate_code($1->code, $3->code, '/'); }
    ;

factor: NUMBER              { char buf[10]; sprintf(buf, "%d", $1); $$ = create_node(buf); }
      | ID                  { $$ = create_node($1); }
      ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter an arithmetic expression (e.g., a + b * c):\n");
    yyparse();
    return 0;
}