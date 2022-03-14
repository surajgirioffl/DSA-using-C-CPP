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

labor *createNode();
void insertNode();
void display();

/*-----------definition of functions started---------------*/
int main()
{
    int choice;
    while (1)
    {
        puts("Press 1 to insert a new node.");
        puts("Press 2 to display the nodes from current node to first node:");
        puts("Press 3 to exit");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            insertNode();
            break;

        case 2:
            display();
            break;

        case 3:
            exit(1);

        default:
            puts("wrong choice");
            break;
        }
    }
}

/*To display the created nodes existing at and before the current position of 'start'*/
void display()
{
    // we have to check if node is empty or not
    if (start == NULL)
        puts("Linked list doesn't exist");
    else
    {
        puts("Data are following:");
        // we will not shift the position of start.
        // so we will take another variable to store start
        labor *temp = start;
        while (temp != NULL) // temp->prv!=NULL will not work for 1st node
        {
            printf("-> %d %s\n", temp->wage, temp->name);
            temp = temp->prv;
        }
        printf("\n");
    }
}

/*To insert a node in continuous manner*/
void insertNode()
{
    labor *ptr = createNode();

    /*
     *we have to check condition if linked list is existing or not
     * start will contains the details of last inserted node
     *if no node existing then start contains NULL.
     */

    if (start == NULL)
        start = ptr;
    else
    {
        start->next = ptr;
        ptr->prv = start;
        start = ptr;
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