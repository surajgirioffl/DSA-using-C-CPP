/*simple basic concept of stack using static array without any functions*/
/* on integer type array (It works for integer and real)*/
#include <stdio.h>
int main()
{
    int stack[10]; // taking an array of size 10
    int top = -1;

    // push operation
    if (top == 9)
        puts("Stack overflow.\n");
    else
    {
        int number;
        puts("write number to push:");
        scanf("%d", &number);
        fflush(stdin);
        top++;
        stack[top] = number;
    }

    // pop operation
    if (top == -1)
        puts("Stack is empty.\n");
    else
    {
        printf("Remove element from stack is %d\n", stack[top]);
        top--; // decreasing the size of top by 1
    }
    return 0;
}
