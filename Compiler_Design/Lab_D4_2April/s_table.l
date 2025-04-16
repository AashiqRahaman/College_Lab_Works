%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct Symbol {
    char name[50];       
    int address;         
    struct Symbol *next; 
} Symbol;
Symbol* symbolTable[SIZE];
int next_address = 1000; // Starting address
int hash(char* name) {
    int hashVal = 0;
    for (int i = 0; name[i] != '\0'; i++)
        hashVal += name[i];
    return hashVal % SIZE;
}
int lookup_or_insert(char* name) {
    int index = hash(name);              
    Symbol* curr = symbolTable[index];  
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            printf("[FOUND] %s at address %d\n", name, curr->address);
            return curr->address;
        }
        curr = curr->next;
    }
    Symbol* newSym = (Symbol*)malloc(sizeof(Symbol));
    strcpy(newSym->name, name);
    newSym->address = next_address;
    next_address += 4; 
    newSym->next = symbolTable[index];
    symbolTable[index] = newSym;
    printf("[INSERTED] %s at address %d\n", name, newSym->address);
    return newSym->address;
}
%}
%option noyywrap 
%%
[a-zA-Z_][a-zA-Z0-9_]*   { lookup_or_insert(yytext); }  
[ \t\n]+                 ;  
.                        ;  
%%
int main() {
    printf("Reading input file and building symbol table...\n");
    yylex(); 
    return 0;
}