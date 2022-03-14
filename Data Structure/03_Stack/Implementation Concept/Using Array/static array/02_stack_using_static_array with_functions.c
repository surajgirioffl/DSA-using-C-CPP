/*Implementation of stack using static array with minimum functions (global top)*/
/* on integer type array (It works for integer and real)*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int top = -1;
void push(int *stack);
void pop(int *stack);
void display(int *stack);

int main()
{
    int choice = 0;
    int stack[SIZE];

    while (1)
    {
        system("pause");
        system("cls");
        puts("1. To push number.");
        puts("2. To pop number.");
        puts("3. To display the stack.");
        puts("4. To exit.");
        printf("$ ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            push(stack);
            break;

        case 2:
            pop(stack);
            break;
        case 3:
            display(stack);
            break;
        case 4:
            exit(EXIT_SUCCESS);
        default:
            puts("wrong choice selected.");
        }
    }
    return 0;
}

void push(int *stack)
{
    if (top == SIZE - 1)
        puts("Stack Overflow.");
    else
    {
        int number;
        puts("write number to push:");
        scanf("%d", &number);
        top++;
        stack[top] = number;
    }
}

void pop(int *stack)
{
    if (top == -1)
        puts("Stack is empty.");
    else
    {
        printf("Removed element is %d.\n", stack[top]);
        top--;
    }
}

void display(int *stack)
{
    if (top == -1)
        puts("Stack is empty.");
    else
    {
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}
