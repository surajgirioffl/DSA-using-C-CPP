/* Stack implementation on string using static array with functions(local top)*/
/*on multiple strings. 2 dimensional array*/
#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
void push(int *top, char stack[][30]);
void pop(int *top, char stack[][30]);
void display(int *top, char stack[][30]);
int isempty(int *top);
int isfull(int *top);

int main()
{
    int choice = 0;
    char stack[SIZE][30]; // allocating memory statically
    int top = -1;

    while (1)
    {
        system("pause");
        system("cls");
        puts("1. To push string.");
        puts("2. To pop string.");
        puts("3. To display the stack.");
        puts("4. To exit.");
        printf("$ ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            push(&top, stack);
            break;

        case 2:
            pop(&top, stack);
            break;
        case 3:
            display(&top, stack);
            break;
        case 4:
            exit(EXIT_SUCCESS);
        default:
            puts("wrong choice selected.");
        }
    }
    return 0;
}

void push(int *top, char stack[][30])
{
    if (isfull(top))
        puts("Stack overflow");
    else
    {
        (*top)++;
        puts("write the string:");
        gets(stack[*top]);
    }
}
void pop(int *top, char stack[][30])
{
    if (isempty(top))
        puts("Stack is empty");
    else
    {
        printf("Poped String is '%s'\n", stack[*top]);
        (*top)--;
    }
}
void display(int *top, char stack[][30])
{
    if (isempty(top))
        puts("Stack is empty");
    else
    {
        puts("Stack data is following:");
        for (int i = (*top); i >= 0; i--)
            printf("%d %s\n", i, stack[i]);
    }
}

/*return 1 if stack is empty else 0*/
int isempty(int *top)
{
    if ((*top) == -1)
        return 1;
    return 0;
}

/*return 1 if stack is full else 0*/
int isfull(int *top)
{
    if ((*top) == SIZE - 1)
        return 1;
    return 0;
}
