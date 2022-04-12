/*stack using structure and applying stack on structure data member*/
#include <stdio.h>
#include <stdlib.h>
#define max 5
typedef struct stack
{
    int array[max];
    int top;
} stack;

/*returns 1 if empty else 0*/
int isEmpty(int top)
{
    if (top == -1)
        return 1;
    return 0;
}
/*returns 1 if full else 0*/
int isFull(int top)
{
    if (top == max - 1)
        return 1;
    return 0;
}

/*push the data in to array present inside the structure which currently pointing*/
void push(stack *var, int data)
{
    if (isFull(var->top))
        puts("stack overflow.");
    else
        var->array[++(var->top)] = data;
    // var->*(array + (++(var->top))) = data;
}

/*pop the top element of array member of structure which is currently pointing*/
int pop(stack *var)
{
    if (isEmpty(var->top))
        puts("stack underflow.");
    else
        return var->array[(var->top)--];

    // return var->*(array + ((var->top)--));
}

/*display the array which is data member of the structure*/
void display(stack var)
{
    if (isEmpty(var.top))
    {
        puts("stack underflow.");
        return;
    }
    puts("\nstack is following:");
    for (int i = var.top; i >= 0; i--)
        printf("%d\n", var.array[i]);
}

int main()
{
    stack var;
    var.top = -1; // if empty
    int choice;
    while (1)
    {
        puts("\npress 1 for push");
        puts("press 2 for pop");
        puts("press 3 to display");
        puts("press 4 for clear the screen");
        puts("press 5 to exit");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
            int data;
        case 1:
            puts("write number to push");
            scanf("%d", &data);
            push(&var, data);
            break;
        case 2:
            printf("poped data is %d", pop(&var));
            break;
        case 3:
            display(var);
            break;
        case 4:
            system("cls");
            break;
        case 5:
            exit(EXIT_SUCCESS);
            break;
        }
    }
}