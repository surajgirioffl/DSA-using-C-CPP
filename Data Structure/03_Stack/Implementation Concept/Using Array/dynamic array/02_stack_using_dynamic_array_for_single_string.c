/*Implementation of stack for single string dynamic array using function (local top)*/
#include <stdlib.h>
#include <stdio.h>

void push(int *top, char *stack, int length);
void pop(int *top, char *stack);
void display(int *top, char *stack);
int isFull(int *top, int length);
int isEmpty(int *top);

int main()
{
    int length;
    int top = -1;
    puts("write the length of string that you want to enter:");
    scanf("%d", &length);
    char *stack = (char *)calloc(length, sizeof(char));
    fflush(stdin);
    while (1)
    {
        puts("Press 1 to push");
        puts("Press 2 to pop");
        puts("Press 3 to display");
        puts("Press 4 to exit");
        printf("$ ");
        int choice;
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
        case 1:
            push(&top, stack, length);
            break;

        case 2:
            pop(&top, stack);
            break;

        case 3:
            display(&top, stack);
            break;

        case 4:
            exit(1);
        default:
            puts("wrong choice selected.");
        }
        system("pause");
        system("cls");
    } // end of while
    return 0;
} // end of main

void push(int *top, char *stack, int length)
{
    if (isFull(top, length))
        puts("Stack overflow.");
    else
    {
        char ch;
        printf("write one character of string:\n");
        scanf("%c", &ch);
        fflush(stdin);
        (*top)++;
        stack[*top] = ch;
    }
}

void pop(int *top, char *stack)
{
    if (isEmpty(top))
        puts("Stack is empty.");
    else
    {
        printf("Removed element is %c.\n", stack[*top]);
        (*top)--;
    }
}

void display(int *top, char *stack)
{
    if (isEmpty(top))
        puts("Stack is empty.");
    else
    {
        puts("content of stack is following:");
        for (int i = (*top); i >= 0; i--)
            printf("%c\n", *(stack + i)); // we can also use stack[i] simply
    }
}

/*returns 1 if full else return 0*/
int isFull(int *top, int length)
{
    if ((*top) == length - 1)
        return 1;
    return 0;
}

/*returns 1 if empty else return 0*/
int isEmpty(int *top)
{
    if ((*top) == -1)
        return 1;
    return 0;
}