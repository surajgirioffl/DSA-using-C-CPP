/*stack implementation using linked list*/

#include <stdio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *next;
};
typedef struct list list;

void display(list *top)
{
    if (isEmpty(top))
        puts("Stack is empty. Underflow.");
    else
    {
        // we have to show only. So, we can't change the current poiting position of top i.e top of stack
        // list *temp = top;
        //no need to take extra variabl
        while (top != NULL)
        {
            printf("%d\n", top->data);
            top = top->next;
        }
    }
}

list *pop(list *top)
{
    if (isEmpty(top))
        puts("Stack is empty. Underflow.");
    else
    {
        // we have to free the space other we can simply write top=top->next
        list *temp; // help in freeing the memory
        temp = top;
        printf("Remove data is %d.\n", temp->data);
        top = top->next; // poiting to node available below it.
        free(temp);
    }
    return top;
}

list *push(list *top)
{
    list *ptr = (list *)malloc(sizeof(list));
    if (ptr == NULL) // no memory allocated
        puts("stack overflow.");
    else
    {
        createNode(ptr);
        ptr->next = top;
        top = ptr; // It's not work. Because we are changing the copied address and the address is remain safe in main(). So we have to return the new address of top and assign it to the main() top.
    }
    return top;
}

/*returns 1 if empty else 0*/
int isEmpty(list *top)
{
    if (top == NULL)
        return 1;
    return 0;
}

/*create a node of list type on given address*/
void createNode(list *ptr)
{
    puts("write data (number):");
    scanf("%d", &ptr->data);
}

int main()
{
    list *top = NULL;
    while (1)
    {
        system("pause");
        system("cls");
        puts("1. To push in stack of list.");
        puts("2. To pop number from stack of list.");
        puts("3. To display the stack.");
        puts("4. To exit.");
        printf("$ ");
        int choice;
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            top = push(top);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            exit(1);
        default:
            puts("Wrong choice selected.");
        }
    }
    return 0;
}