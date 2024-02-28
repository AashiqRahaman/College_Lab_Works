#include <stdio.h>
#include <stdlib.h>
#define Max 5
int top= (-1);
int stack_arr[Max];
void push(int value)
{   if (top == Max - 1)
    {printf ("Stack Overflow \n");
    return;}
    top += 1;
    stack_arr[top] = value; }
int pop()
{   int x;
    if (top== -1)
    {printf ("Stack Underflow");
    exit(1);                    }
    x= stack_arr[top];
    top = top -1;
    return x; }
void print()
{   if (top < 0)
    {printf("stack is now empty");
    return; }
    printf("Here is Your Current Stack's Elemenmts\n [");
    for(int i=top;i>=0;i--)
    {printf(" %d ",stack_arr[i]);}
    printf("]\n"); }
void main()
{   push(10);
    push(5);
    push(3);
    pop();
    print();  }
