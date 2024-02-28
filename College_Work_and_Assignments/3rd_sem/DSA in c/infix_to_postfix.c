#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Stack data structure
#define MAX_STACK_SIZE 100

typedef struct
{
    char data[MAX_STACK_SIZE];
    int top;
} Stack;

void initialize(Stack *stack)
{
    stack->top = -1;
}

void push(Stack *stack, char item)
{
    if (stack->top < MAX_STACK_SIZE - 1)
    {
        stack->data[++(stack->top)] = item;
    }
}

char pop(Stack *stack)
{
    if (stack->top >= 0)
    {
        return stack->data[(stack->top)--];
    }
    return '\0';
}

char peek(Stack *stack)
{
    if (stack->top >= 0)
    {
        return stack->data[stack->top];
    }
    return '\0';
}

bool isOperand(char ch)
{
    return isalnum(ch);
}

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

bool checkInfixValidity(const char *expression)
{
    // Implement infix validation logic here
    // Return true if valid, false otherwise
}

bool checkPostfixValidity(const char *expression)
{
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isOperand(expression[i]))
        {
            push(&stack, expression[i]);
        }
        else if (isOperator(expression[i]))
        {
            if (stack.top < 1)
            {
                return false;
            }
            pop(&stack);
        }
    }

    return (stack.top == 0);
}

bool checkPrefixValidity(const char *expression)
{
    Stack stack;
    initialize(&stack);

    for (int i = strlen(expression) - 1; i >= 0; i--)
    {
        if (isOperand(expression[i]))
        {
            push(&stack, expression[i]);
        }
        else if (isOperator(expression[i]))
        {
            if (stack.top < 1)
            {
                return false;
            }
            pop(&stack);
        }
    }

    return (stack.top == 0);
}

int main()
{
    char infixExpression[] = "(a+b)*c";
    char postfixExpression[] = "ab+c*";
    char prefixExpression[] = "*+abc";

    if (checkInfixValidity(infixExpression))
    {
        printf("Infix expression is valid.\n");
    }
    else
    {
        printf("Infix expression is invalid.\n");
    }

    if (checkPostfixValidity(postfixExpression))
    {
        printf("Postfix expression is valid.\n");
    }
    else
    {
        printf("Postfix expression is invalid.\n");
    }

    if (checkPrefixValidity(prefixExpression))
    {
        printf("Prefix expression is valid.\n");
    }
    else
    {
        printf("Prefix expression is invalid.\n");
    }

    return 0;
}
