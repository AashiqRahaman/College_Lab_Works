%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define size of the hash table
#define SIZE 100

// Define a struct for each symbol
typedef struct Symbol {
    char name[50];       // Name of the identifier
    int address;         // Memory address assigned
    struct Symbol *next; // For chaining (collision resolution)
} Symbol;

// Hash table array of pointers to Symbol
Symbol* symbolTable[SIZE];
int next_address = 1000; // Starting address

// Simple hash function (based on character sum)
int hash(char* name) {
    int hashVal = 0;
    for (int i = 0; name[i] != '\0'; i++)
        hashVal += name[i];
    return hashVal % SIZE;
}

// Lookup or insert identifier into the symbol table
int lookup_or_insert(char* name) {
    int index = hash(name);              // Get hash index
    Symbol* curr = symbolTable[index];  // Go to that bucket

    // Check if already exists
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            printf("[FOUND] %s at address %d\n", name, curr->address);
            return curr->address;
        }
        curr = curr->next;
    }

    // Not found → Insert
    Symbol* newSym = (Symbol*)malloc(sizeof(Symbol));
    strcpy(newSym->name, name);
    newSym->address = next_address;
    next_address += 4; // Increment address by 4 bytes
    newSym->next = symbolTable[index];
    symbolTable[index] = newSym;

    printf("[INSERTED] %s at address %d\n", name, newSym->address);
    return newSym->address;
}
%}

%option noyywrap 
 // Don't look for yywrap() function

%%
[a-zA-Z_][a-zA-Z0-9_]*   { lookup_or_insert(yytext); }  // Match identifiers
[ \t\n]+                 ;  // Ignore whitespace
.                        ;  // Ignore all other characters
%%

int main() {
    printf("Reading input file and building symbol table...\n");
    yylex();  // Start lexical analysis
    return 0;
}


