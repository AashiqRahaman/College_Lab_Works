#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void removeSpaces(char* source) {
    int i, j = 0;
    for (i = 0; source[i]; i++)
        if (!isspace(source[i]))
            source[j++] = source[i];
    source[j] = '\0';
}

// Get operator precedence
int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Generate intermediate code for a simple expression
void generateIntermediateCode(char* expr) {
    char lhs, op1, op2;
    char a, b, c;
    int tempCount = 1;

    removeSpaces(expr);  // Remove spaces like a=b + c*d

    // Format assumed: a=b op1 c op2 d  (max 3 variables, 2 operators)
    if (sscanf(expr, "%c=%c%c%c%c", &lhs, &a, &op1, &b, &op2) == 5) {
        c = expr[6]; // the 3rd variable

        // Compare precedence
        if (precedence(op1) < precedence(op2)) {
            // op2 has higher precedence: compute b op2 c first
            printf("t%d = %c %c %c\n", tempCount, b, op2, c);
            printf("t%d = %c %c t%d\n", tempCount + 1, a, op1, tempCount);
            printf("%c = t%d\n", lhs, tempCount + 1);
        } else {
            // op1 has higher or equal precedence: compute a op1 b first
            printf("t%d = %c %c %c\n", tempCount, a, op1, b);
            printf("t%d = t%d %c %c\n", tempCount + 1, tempCount, op2, c);
            printf("%c = t%d\n", lhs, tempCount + 1);
        }
    } else if (sscanf(expr, "%c=%c%c%c", &lhs, &a, &op1, &b) == 4) {
        // Format: a = b op c
        printf("t1 = %c %c %c\n", a, op1, b);
        printf("%c = t1\n", lhs);
    } else {
        printf("Unsupported expression format.\n");
    }
}

int main() {
    char expr[MAX];
    printf("Enter the expression (e.g., a=b+c*d): ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';  // Remove newline
    generateIntermediateCode(expr);
    return 0;
}
