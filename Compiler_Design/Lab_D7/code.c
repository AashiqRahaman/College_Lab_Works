#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Function to generate intermediate code
void generateIntermediateCode(char* expression) {
    char var1, var2, var3,var4;
    char op1, op2;

    // Extracting the variables and operators from the expression
    sscanf(expression, "%c = %c%c%c%c%c", &var1, &var2, &op1,&var3, &op2, &var4);

    // Generate intermediate code
    // t1 = b * c
    printf("t1 = %c%c%c\n", var2, op1, var3);

    // t2 = t1 + d
    printf("t2 = t1 + %c\n", var4);

    // a = t2
    printf("%c = t2\n", var1);
}

int main() {
    char expression[MAX_SIZE];

    // Input the expression
    printf("Enter the expression (e.g., a = b*c+d): ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';  // Remove newline character if any

    // Generate intermediate code
    generateIntermediateCode(expression);

    return 0;
}
