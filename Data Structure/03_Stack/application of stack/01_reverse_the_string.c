/*stack implementation to reverse the string*/
#define max 10
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void push(int *top, char *stack, char data)
{
    if ((*top) == max - 1)
        puts("stack overflow");
    else
        stack[++(*top)] = data;
}

char pop(int *top, char *stack)
{
    if ((*top) == -1)
    {
        puts("stack underflow.");
        exit(-1);
    }

    return stack[(*top)--];
}

int main()
{
    char string[max]; // for string operations
    char stack[max];  // for stack operations
    puts("\nWrite the string:");
    gets(string);

    int top = -1; // for top of stack
    for (int i = 0; i < strlen(string); i++)
        push(&top, stack, string[i]);
    for (int i = 0; i < strlen(string); i++)
        string[i] = pop(&top, stack);

    printf("Reversed string is %s\n", string);
    return 0;
}