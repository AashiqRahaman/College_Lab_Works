%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Symbol {
    char* name;
    struct Symbol* next;
} Symbol;

Symbol* symbol_table[TABLE_SIZE];

// Hash function
unsigned int hash(char* str) {
    unsigned int hash = 0;
    while (*str)
        hash = (hash << 2) ^ *str++;
    return hash % TABLE_SIZE;
}

// Insert into symbol table
void insert(char* name) {
    unsigned int index = hash(name);
    Symbol* curr = symbol_table[index];

    while (curr) {
        if (strcmp(curr->name, name) == 0) {
            printf("Identifier '%s' already exists at address %p\n", name, (void*)curr);
            return;
        }
        curr = curr->next;
    }

    Symbol* new_sym = (Symbol*)malloc(sizeof(Symbol));
    new_sym->name = strdup(name);
    new_sym->next = symbol_table[index];
    symbol_table[index] = new_sym;

    printf("Inserted identifier '%s' at address %p\n", name, (void*)new_sym);
}

void yyerror(const char* msg) {
    fprintf(stderr, "Syntax Error: %s\n", msg);
}
%}

%union {
    char* str;
}

%token <str> ID

%%

program:
    | program statement
    ;

statement:
    ID { insert($1); free($1); }
    ;

%%

int main() {
    printf("=== Begin Symbol Table Parsing ===\n");
    yyparse();
    printf("=== End Symbol Table Parsing ===\n");
    return 0;
}
