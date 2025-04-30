%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char lhs;
char var1, var2, var3;
char op1 = '\0', op2 = '\0';
int tempCount = 1;
int stage = 0;
%}

%%

[ \t\n]+        ;  // Ignore whitespace

[a-zA-Z]        {
                    if (stage == 0) {
                        lhs = yytext[0];
                        stage++;
                    } else if (stage == 1) {
                        var1 = yytext[0];
                        stage++;
                    } else if (stage == 3) {
                        var2 = yytext[0];
                        stage++;
                    } else if (stage == 5) {
                        var3 = yytext[0];
                        stage++;
                    }
                }

"="             { stage++; }
"*"|"/"|"+"|"-" {
                    if (stage == 2) {
                        op1 = yytext[0];
                        stage++;
                    } else if (stage == 4) {
                        op2 = yytext[0];
                        stage++;
                    }
                }

.               ;  // Ignore other characters

%%

int main() {
    printf("Enter expression (e.g., a = b + c * d): ");
    yylex();

    if (op2 != '\0') {
        // Expression with two operators
        if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) {
            // op2 has higher precedence
            printf("t1 = %c %c %c\n", var2, op2, var3);
            printf("t2 = %c %c t1\n", var1, op1);
            printf("%c = t2\n", lhs);
        } else {
            // op1 has higher or equal precedence
            printf("t1 = %c %c %c\n", var1, op1, var2);
            printf("t2 = t1 %c %c\n", op2, var3);
            printf("%c = t2\n", lhs);
        }
    } else {
        // Expression with one operator
        printf("t1 = %c %c %c\n", var1, op1, var2);
        printf("%c = t1\n", lhs);
    }

    return 0;
}

int yywrap() {
    return 1;
}
