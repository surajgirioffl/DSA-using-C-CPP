/* implementation of stack using dynamic array with maximum functions (local top)*/
/* on integer type array (It works for integer and real)*/

#include <stdlib.h>
#include <stdio.h>

int isempty(int *top);
int isfull(int size, int *top);
int push(int *stack, int size, int *top);
int pop(int *stack, int *top);
int display(int *stack, int size, int *top);

int main()
{
    int choice = 0;
    int *stack = NULL; // currently doesn't pointing anywhere
    int size;
    puts("what's size of stack do you want implement?");
    scanf("%d", &size);
    fflush(stdin);
    stack = (int *)malloc(size * sizeof(int));
    int top = -1;

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
            push(stack, size, &top);
            break;

        case 2:
            pop(stack, &top);
            break;
        case 3:
            display(stack, size, &top);
            break;
        case 4:
            exit(EXIT_SUCCESS);
        default:
            puts("wrong choice selected.");
        }
    }
    return 0;
}

/*return 1 if stack is empty else return 0*/
int isempty(int *top)
{
    if (*top == -1)
        return 1;
    return 0;
}

/*return 1 if stack is full else return 0*/
int isfull(int size, int *top)
{
    if (*top == size - 1)
        return 1;
    return 0;
}

int push(int *stack, int size, int *top)
{
    if (isfull(size, top))
        puts("Stack Overflow.");
    else
    {
        int number;
        puts("write the number:");
        scanf("%d", &number);
        fflush(stdin);
        (*top)++;
        stack[*top] = number;
    }
}

int pop(int *stack, int *top)
{
    if (isempty(top))
        puts("Stack is empty.");
    else
    {
        printf("Removed element is %d.\n", stack[*top]);
        (*top)--;
    }
}

int display(int *stack, int size, int *top)
{
    if (isempty(top))
        puts("Stack is empty.");
    else
    {
        puts("\nStack data is following:");
        for (int i = (*top); i >= 0; i--)
            printf("%d\n", *(stack + i)); // we can also use stack[i] simply no issue
    }
}