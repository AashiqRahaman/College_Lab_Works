#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int tempCount = 1;

char* newTemp(char* buf) {
    sprintf(buf, "t%d", tempCount++);
    return buf;
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

void processExpression(char* lhs, char* rhs) {
    char operators[MAX], operands[MAX][MAX];
    int topOp = -1, topVal = -1;
    char temp[10];
    int i = 0, len = strlen(rhs);

    while (i < len) {
        if (isspace(rhs[i])) {
            i++;
            continue;
        }

        if (isalnum(rhs[i])) {
            char val[2] = {rhs[i], '\0'};
            strcpy(operands[++topVal], val);
            i++;
        }
        else if (rhs[i] == '(') {
            operators[++topOp] = rhs[i++];
        }
        else if (rhs[i] == ')') {
            while (topOp >= 0 && operators[topOp] != '(') {
                char op = operators[topOp--];
                char val2[MAX], val1[MAX];

                strcpy(val2, operands[topVal--]);
                strcpy(val1, operands[topVal--]);

                newTemp(temp);
                printf("%s = %s %c %s\n", temp, val1, op, val2);
                strcpy(operands[++topVal], temp);
            }
            topOp--; // pop '('
            i++;
        }
        else if (isOperator(rhs[i])) {
            while (topOp >= 0 && operators[topOp] != '(' &&
                   precedence(operators[topOp]) >= precedence(rhs[i])) {
                char op = operators[topOp--];
                char val2[MAX], val1[MAX];

                strcpy(val2, operands[topVal--]);
                strcpy(val1, operands[topVal--]);

                newTemp(temp);
                printf("%s = %s %c %s\n", temp, val1, op, val2);
                strcpy(operands[++topVal], temp);
            }
            operators[++topOp] = rhs[i++];
        }
        else {
            printf("Unknown character: %c\n", rhs[i]);
            return;
        }
    }

    while (topOp >= 0) {
        char op = operators[topOp--];
        char val2[MAX], val1[MAX];

        strcpy(val2, operands[topVal--]);
        strcpy(val1, operands[topVal--]);

        newTemp(temp);
        printf("%s = %s %c %s\n", temp, val1, op, val2);
        strcpy(operands[++topVal], temp);
    }

    printf("%s = %s\n", lhs, operands[topVal]);
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        perror("Error opening input.txt");
        return 1;
    }

    char line[200];
    printf("Intermediate Code:\n\n");

    while (fgets(line, sizeof(line), fp)) {
        if (strchr(line, '=')) {
            char lhs[10], rhs[150];
            sscanf(line, " %[^= ] = %[^\n]", lhs, rhs);
            processExpression(lhs, rhs);
        }
    }

    fclose(fp);
    return 0;
}