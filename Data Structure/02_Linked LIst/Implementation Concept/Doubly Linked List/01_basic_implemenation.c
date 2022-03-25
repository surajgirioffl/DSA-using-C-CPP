/*Implemenation of concept of doubly linked list using c*/

/*
 *operations
 *insert in empty list
 *insert at beginning of list
 *insertion at end of list
 *insertion in between the node
 *same as above in delete
 *display all from beginning of list
 *display all from end of list
 *display from particular node
 *display only particular node
 */

/*
 *author: Suraj Kumar Giri.
 *Date: 12-02-2022
 *Time: 11:04:49
 */
#include <stdio.h>
#include <stdlib.h>
struct labor
{
    struct labor *prv; // for pointing on previous node of current node
    char name[30];
    int wage;           // for wage of labor
    struct labor *next; // for pointing on next node of current node
} * start;              // taking start as global variable. So, don't need to pass to every function.

typedef struct labor labor; // making simple data type 'labor' instead of 'struct labor'
labor *top;                 // taking top global pointer variable for storing the address pointing at top

labor *createNode();

/*functions*/
void insertAtDesiredPosition()
{
    int position; // take node number position from user
    puts("write position or node number to insert a node before or after it.");
    scanf("%d", &position);

    printf("Press 1 for to insert before desired position number or node number %d.", position);
    printf("Press 2 for to insert after desired position number or node number %d.", position);
    printf("Press 3 for to insert at desired position number or node number %d.", position);

    labor *temp = start;
    switch (position)
    {
        /* for insert before desired position*/
    case 1:
    
        break;

        /*for insert after desired position */
    case 2:
        break;

        /*for insert at desired position*/
    case 3:
        break;

    default:
        puts("Wrong Choice Selected.");
        break;
    }
}

/*To display the existing from the beginning of the list*/
void displayFromBeginning()
{
    // we have to check if node is empty or not
    if (start == NULL)
        puts("Linked list doesn't exist");
    else
    {
        puts("Data are following:");
        // we will not shift the position of start.
        // so we will take another variable to store start
        labor *temp = top;   // because we want to print from beginning
        while (temp != NULL) // temp->prv!=NULL will not work for 1st node
        {
            printf("-> %d %s\n", temp->wage, temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

/*To insert a node in continuous manner*/
void insertNodeAtEnd()
{
    labor *newNode = createNode();

    /*
     *we have to check condition if linked list is existing or not
     * start will contains the details of last inserted node
     *if no node existing then start contains NULL.
     */

    if (start == NULL)
    {
        start = newNode;
        top = newNode; // now top will point to first node
    }
    else
    {
        labor *temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        // after the 'while' loop tmp will point to last node
        // now linking newnode with last node of linked list
        temp->next = newNode;
        newNode->prv = temp;
        start = newNode; // now start will point to last created node
    }
}

/* To create a newNode. Retuns the base address of created newNode. Retuns NULL if memory will not allocated*/
labor *createNode()
{
    labor *newNode = (labor *)malloc(sizeof(labor)); // creating a new node at random address
    if (newNode != NULL)
    {
        newNode->prv = NULL;
        newNode->next = NULL;
        // taking data from user to store in data part of node
        puts("write name of labor:");
        gets(newNode->name);
        printf("write wage of %s.\n", newNode->name);
        scanf("%d", &newNode->wage);
        fflush(stdin);
    }
    return newNode; // returning the base address of created node
}

/*-----------definition of functions started---------------*/
int main()
{
    int choice;
    system("cls");
    while (1)
    {
        puts("Press 1 to insert a new node.");
        puts("Press 2 to display the nodes from beginning of linked list:");
        puts("Press 3 to exit");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            insertNodeAtEnd();
            break;

        case 2:
            displayFromBeginning();
            break;

        case 3:
            exit(1);

        default:
            puts("wrong choice");
            break;
        }
    }
}
