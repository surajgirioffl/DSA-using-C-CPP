/*stack using structure with static array.
 *applying stack on structure object i.e variable.
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct biodata
{
    char name[30];
    char class[30];
    int totalMarks;
};
typedef struct biodata biodata;
void push(int *top, biodata *stack); // we can use 'biodata stack' if we have to pass single variable but we are passing array of biodata type. so we have to store the same in same type pointer
void pop(int *top, biodata *stack);
void display(int *top, biodata *stack);
int isFull(int *top);
int isEmpty(int *top);

int main()
{
    int choice = 0;
    biodata stack[SIZE]; // allocating memory statically
    int top = -1;

    while (1)
    {
        system("pause");
        system("cls");
        puts("1. To push data in stack.");
        puts("2. To pop from stack.");
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

void push(int *top, biodata *stack)
{
    if (isFull(top))
        puts("Stack overflow.");
    else
    {
        (*top)++;
        puts("write name:");
        gets(stack[*top].name);
        // gets((stack + (*top))->name);//we can also use it
        printf("write class of %s:\n", stack[*top].name);
        gets(stack[*top].class);
        printf("write total marks of %s:\n", stack[*top].name);
        scanf("%d", &stack[*top].totalMarks);
        fflush(stdin);
    }
}

void pop(int *top, biodata *stack)
{
    if (isEmpty(top))
        puts("Stack is empty.");
    else
    {
        printf("Remove element is %s %s %d\n", stack[*top].name, stack[*top].class, stack[*top].totalMarks);
        (*top)--;
    }
}

void display(int *top, biodata *stack)
{
    if (isEmpty(top))
        puts("Stack is empty.");
    else
    {
        puts("Data in stack is following:");
        for (int i = (*top); i >= 0; i--)
            printf("%d  %s %s %d\n", i, stack[i].name, stack[i].class, stack[i].totalMarks);
    }
}

/*returns 1 if stack is full, 0 otherwise*/
int isFull(int *top)
{
    if ((*top) == SIZE - 1)
        return 1;
    return 0;
}

/*returns 1 if stack is empty else 0 otherwise*/
int isEmpty(int *top)
{
    if ((*top) == -1)
        return 1;
    return 0;
}