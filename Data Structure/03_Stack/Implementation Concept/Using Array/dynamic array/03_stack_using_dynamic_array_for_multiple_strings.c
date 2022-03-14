/*stack for multiple string using dynamic array (with local top)*/
#include <stdio.h>
#include <stdlib.h>

void push(int *top, char **stack, int size);
void pop(int *top, char **stack);
void display(int *top, char **stack);
int isFull(int *top, int size);
int isEmpty(int *top);

int main()
{
    int choice = 0;
    int size;
    printf("How many strings do you want to add in the stack.\n");
    scanf("%d", &size);
    char **stack = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) // allocating memory to each one dimensional array
        stack[i] = (char *)malloc(30 * sizeof(char));
    fflush(stdin);
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
            push(&top, stack, size);
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
} // end of main

void push(int *top, char **stack, int size)
{
    if (isFull(top, size))
        puts("Stack Overflow.");
    else
    {
        (*top)++;
        puts("write the string:");
        gets(stack[*top]);
    }
}
void pop(int *top, char **stack)
{
    if (isEmpty(top))
        puts("Stack is empty.");
    else
    {
        printf("Removed element is %s.\n", stack[*top]);
        (*top)--;
    }
}

void display(int *top, char **stack)
{
    if (isEmpty(top))
        puts("Stack is empty.");
    else
    {
        puts("Stack is following:");
        for (int i = (*top); i >= 0; i--)
            printf("%d %s\n", i, stack[i]);
    }
}

/*return 1 if top is full, 0 otherwise */
int isFull(int *top, int size)
{
    if ((*top) == size - 1)
        return 1;
    return 0;
}

/*returns 1 if stack is empty, 0 otherwise*/
int isEmpty(int *top)
{
    if ((*top) == -1)
        return 1;
    return 0;
}