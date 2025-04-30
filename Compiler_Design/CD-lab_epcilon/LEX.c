// write a c programe which converts an input c program into lex by identifing the keywords and identifier.
// write a lex programe which converts an input c program into lex by identifing the keywords and identifier.
#include <stdio.h>

#include <string.h>
#include <stdlib.h>

#define MAX_KEYWORDS 20
#define MAX_IDENTIFIERS 20

int isKeyword(char *word) {
    char *keywords[] = {"#include","<stdio.h>","#define","auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    int i;
    for (i = 0; i < MAX_KEYWORDS; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *input, *output;
    char ch, word[100];
    int isIdentifier = 0;
    int isKeywordFound = 0;
    int i = 0;
    // int j = 0;
    // int k = 0;
    // int l = 0;
    // int m = 0;
    // int n = 0;
    // int o = 0;
    // int p = 0;
    // int q = 0;
    // int r = 0;


    input = fopen("input.c", "r");
    output = fopen("output.txt", "w");
    if (input == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }
    if (output == NULL) {
        printf("Error opening output file!\n");
        fclose(input);
        return 1;
    }
    while ((ch = fgetc(input)) != EOF) {
        if (isalpha(ch) || ch == '_')
        {
            if (!isIdentifier) {
                isIdentifier = 1;
                word[i] = ch;
                i++;
            } else {
                word[i] = ch;
                i++;
            }
        } else if (isIdentifier && (ch == ' ' || ch == '\t' || ch == '\n' || ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == ':' || ch == '.' || ch == '?' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' || ch == '&' || ch == '|' || ch == '~' || ch == '<' || ch == '>' || ch == '=' || ch == '!')) {
            word[i] = '\0';
            isIdentifier = 0;
            i = 0;
            if (isKeyword(word)) {
                fprintf(output, "Keyword: %s\n", word);
            } else {
                fprintf(output, "Identifier: %s\n", word);
            }
        } else if (ch == '#') {
            while ((ch = fgetc(input)) != '\n' && ch != EOF);
        }
        if (ch == '\n') {
            fprintf(output, "\n");
        }
        if (ch == '\t') {
            fprintf(output, "    ");
        }
        if (ch == ' ') {
            fprintf(output, " ");
        }
        if (ch == ';') {
            fprintf(output, ";\n");
        }
        if (ch == ',') {
            fprintf(output, ", ");
        }
        if (ch == '(') {
            fprintf(output, "(");
        }
        if (ch == ')') {
            fprintf(output, ")");
        }
        if (ch == '{') {
            fprintf(output, "{\n");
        }
        if (ch == '}') {
            fprintf(output, "}\n");
        }
        if (ch == '[') {
            fprintf(output, "[");
        }
        if (ch == ']') {
            fprintf(output, "]");
        }
        if (ch == ':') {
            fprintf(output, ": ");
        }
        if (ch == '.') {
            fprintf(output, ". ");
        }

        if (ch == '?') {
            fprintf(output, "? ");
        }
        if (ch == '+') {
            fprintf(output, "+ ");
        }
        if (ch == '-') {
            fprintf(output, "- ");
        }
        if (ch == '*') {
            fprintf(output, "* ");
        }
        if (ch == '/') {
            fprintf(output, "/ ");
        }
        if (ch == '%') {
            fprintf(output, "% ");
        }
        if (ch == '^') {
            fprintf(output, "^ ");
        }
        if (ch == '&') {
            fprintf(output, "& ");
        }
        if (ch == '|') {
            fprintf(output, "| ");
        }
        if (ch == '~') {
            fprintf(output, "~ ");
        }
        if (ch == '<') {
            fprintf(output, "< ");
        }
        if (ch == '>') {
            fprintf(output, "> ");
        }
        if (ch == '=') {
            fprintf(output, "= ");
        }

        if (ch == '!') {
            fprintf(output, "!");
            ch = fgetc(input);
            if (ch == '=') {
                fprintf(output, "=");
            } else {
                ungetc(ch, input);
            }
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}