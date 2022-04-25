/*Implemenation of concept of doubly linked list using c*/

/*
 **operations
 **1. Insertion
 *insertion at end
 *insertion at beginning
 *insertion before particular node number
 *insertion after particular node number
 *insertion at particular node number
 *
 **2. Deletion
 *deletion at end
 *deletion at beginning
 *deletion of particular node number
 *
 **3. Display
 *display from beginning
 *reverse the list and display from beginning
 *
 **4.
 *Transversal in linked list and modification of data if required
 *
 **5. Searching for data
 *linear search to find a particular data
 */

/*
 *author: Suraj Kumar Giri.
 *Date: 31-03-2022
 *Time: 00:16:54
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct labor labor; // making simple data type 'labor' instead of 'struct labor'
struct labor
{
    labor *prv; // for pointing on previous node of current node
    char name[30];
    int wage;    // for wage of labor
    labor *next; // for pointing on next node of current node
} * start;       // taking start as global variable. So, don't need to pass to every function.
labor *top;      // taking top as global pointer variable for storing the address pointing at top
/*
 *we will use two variable 'top' and 'start' to perform all operations.
 *top will remains fixed at first node.
 *start will change it place as operations performed in list
 */

/*functions */
/*----------------------------------------------------------------*/

labor *createNode();
int totalNodeInList();
int currentPositionOfStart();

void insertionOperationMenu(); // menu
void insertNodeAtEnd();
void insertAtBeginning();
void insertAtDesiredPosition();
void insertBeforeDesiredPosition(position);
void insertAfterDesiredPosition(position);

void deletionOperationMenu(); // menu
void deleteNodeAtEnd();
void deleteAtBeginning();
void deleteAtDesiredPosition();

void displayMenu();
void displayFromBeginning();

void searchDataMenu();

/*-----------definition of functions started---------------*/
int main()
{
    int choice;
    system("cls");
    do
    {
        puts("Press 1 for insertion of new node.");
        puts("Press 2 for deletion of existing node.");
        puts("Press 3 for display the linked list.");
        puts("Press 4 for search data in linked list.");
        puts("Press 9 to clear the display.");
        puts("Press 10 to exit");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            insertionOperationMenu();
            break;

        case 2:
            deletionOperationMenu();
            break;

        case 3:
            displayMenu();
            break;
        case 4:
            searchDataMenu();
            break;
        case 9:
            system("cls");
            break;

            // default:
            //     puts("wrong choice");
            //     break;
        }
    } while (choice != 10);
}

/*------------------INSERTION OPERATIONS-----------------------*/
/*main menu function of insertion Operation in linked list*/
void insertionOperationMenu()
{
    puts("\nPress 1 for insert node in beginning of linked list.");
    puts("Press 2 for insert node in end of linked list.");
    puts("Press 3 for insert node at/before/after desired node number of linked list.");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        insertAtBeginning();
        break;
    case 2:
        insertNodeAtEnd();
        break;
    case 3:
        insertAtDesiredPosition();
        break;
    default:
        puts("wrong choice.");
        break;
    }
}

/*To insert at end of list*/
void insertNodeAtEnd()
{
    labor *newNode = createNode();

    /*
     *we have to check condition if linked list is existing or not
     *start will contains the details of last inserted node
     *if no node existing then start contains NULL.
     *top will also be NULL if no node existing.
     */

    if (top == NULL)
    {
        start = newNode;
        top = newNode; // now top will point to first node
    }
    else
    {
        while (start->next != NULL)
            start = start->next;
        // after the 'while' loop 'start' will point to last node
        // now linking newnode with last node of linked list
        start->next = newNode;
        newNode->prv = start;
        start = newNode; // now start will point to last created node
    }
    puts("Insertion in end of linked list successful.............\n");
}

/*to insert node at beginning of list */
void insertAtBeginning()
{
    labor *newNode = createNode();
    if (top == NULL)
    {
        puts("Linked list doesn't exist.\nSo, we are creating it.");
        top = newNode;
        start = newNode;
    }
    else
    {
        start = top;
        /*now inserting before 'start'.*/
        start->prv = newNode;
        newNode->next = start;
        top = newNode; // now newNode become 1st node
    }

    puts("Insertion at beginning of list successful...............\n");
}

/*to insert node at desired position*/
void insertAtDesiredPosition()
{
    int position; // take node number position from user
    puts("write position or node number to insert a node before or after it.");
    scanf("%d", &position);

    printf("\nPress 1 for to insert before desired position number or node number %d.\n", position);
    printf("Press 2 for to insert after desired position number or node number %d.\n", position);
    printf("Press 3 for to insert at desired position number or node number %d.\n", position);
    int choice;
    scanf("%d", &choice);

    int totalNodes = totalNodeInList();

    if (choice == 3 && totalNodes == 0 && position == 1) // means linked list doesn't exist and user want insert a node at position 1. Means we will create a linked list.
        insertAtBeginning();
    else if (position > totalNodes || position < 1)
    {
        puts("Invalid node number entered.\n");
        return;
    }
    else
    {
        switch (choice)
        {
            /* for insert before desired position*/
        case 1:
            insertBeforeDesiredPosition(position);
            break;

            /*for insert after desired position */
        case 2:
            insertAfterDesiredPosition(position);
            break;

            /*for insert at desired position*/
        case 3:
            insertBeforeDesiredPosition(position);
            // because if user want to insert at position 4 then we insert before it and that will become position 4
            break;

        default:
            puts("Wrong Choice Selected.");
            break;
        }
    }
}

/*to insert a node before desired position*/
void insertBeforeDesiredPosition(int position)
{
    int positionOfStart = currentPositionOfStart();
    labor *newNode = createNode();
    // if (positionOfStart == position)
    // {
    // }
    // else
    /*above is not required. we will write code of linking only once*/
    if (positionOfStart < position)
    {
        while (1)
        {
            start = start->next;
            if (++positionOfStart == position)
                break;
        }
    }
    else if (positionOfStart > position)
    {
        while (1)
        {
            start = start->prv;
            if (--positionOfStart == position)
                break;
        }
    }

    /*after these if-else, position of start will be at user's desired position*/
    // linking
    start->prv->next = newNode;
    newNode->prv = start->prv;
    start->prv = newNode;
    newNode->next = start;
    printf("Your inserted node will indexed at position %d\n", position);
    puts("Insertion before desired node is successful...............");
}

/*to insert after desired position*/
void insertAfterDesiredPosition(int position)
{
    int positionOfStart = currentPositionOfStart();
    labor *newNode = createNode();
    if (positionOfStart < position)
    {
        while (1)
        {
            start = start->next;
            if (++positionOfStart == position)
                break;
        }
    }
    else if (positionOfStart > position)
    {
        while (1)
        {
            start = start->prv;
            if (--positionOfStart == position)
                break;
        }
    }

    // now linking works
    start->next->prv = newNode;
    newNode->next = start->next;
    newNode->prv = start;
    start->next = newNode;
    printf("Your inserted node will indexed at position %d\n", position + 1);
    puts("Insertion after desired node is successful...............");
}

/*----------------OTHER USED FUNCTIONS--------------------*/
/* To create a newNode. Retuns the base address of created newNode. Returns NULL if memory will not allocated*/
labor *createNode()
{
    labor *newNode = (labor *)malloc(sizeof(labor)); // creating a new node at random address
    if (newNode != NULL)
    {
        newNode->prv = NULL;
        newNode->next = NULL;
        // taking data from user to store in data part of node
        puts("write name of labor:");
        fflush(stdin);
        gets(newNode->name);
        printf("write wage of %s.\n", newNode->name);
        scanf("%d", &newNode->wage);
        fflush(stdin);
    }
    return newNode; // returning the base address of created node
}

/*returns total number of nodes in list.*/
int totalNodeInList()
{
    start = top; // now start will point to the 1st node
    if (start == NULL)
        return 0; // if linked list doesn't exist.
    int counter = 1;
    while (start->next != NULL)
    {
        start = start->next;
        counter++;
    }
    return counter;
}

/*returns the current position(node number) of 'start' in list */
int currentPositionOfStart()
{
    int counter = 1;
    labor *temp = top; // tmp will point to the 1st node
    while (1)
    {
        if (temp == start)
            return counter;
        temp = temp->next;
        counter++;
    }
}

/*----------------------Deletion Operation------------------------------*/
/*main menu function of deletion Operation in linked list*/
void deletionOperationMenu()
{
    puts("\nPress 1 for delete node in beginning of linked list.");
    puts("Press 2 for delete node in end of linked list.");
    puts("Press 3 for delete node at/before/after desired node number of linked list.");
    int choice;
    scanf("%d", &choice);
    fflush(stdin);

    switch (choice)
    {
    case 1:
        deleteAtBeginning();
        break;
    case 2:
        deleteNodeAtEnd();
        break;
    case 3:
        deleteAtDesiredPosition();
        break;
    default:
        puts("wrong choice.");
        break;
    }
}

/*to delete node from end of linked list*/
void deleteNodeAtEnd()
{
    if (top == NULL)
    {
        puts("Linked list doesn't exit.");
        return;
    }
    while (start->next != NULL)
        start = start->next;

    // now deleting
    start->prv->next = NULL;
    printf("Last Node (Name = %s & Wage =%d) deleted successfully.........\n\n", start->name, start->wage);
    free(start);
    start = top; // now start will not pointing any node of list. So, we have assigned address of 1st node to 'start'. So,It will pointed in list.
}

/*to delete node from beginning of linked list*/
void deleteAtBeginning()
{
    if (top == NULL)
    {
        puts("Linked list doesn't exit.");
        return;
    }
    // start may be anywhere. so we use 'top' here.
    start = top;
    // now deleting
    start->next->prv = NULL;
    printf("First Node (Name = %s & Wage =%d) deleted successfully.........\n\n", top->name, top->wage);
    top = top->next; // or start->next
    free(start);
    start = top; // now start will not pointing any node of list. So, we have assigned address of 1st node to 'start'. So,It will pointed in list.
}

/*to delete node at user's desired position*/
void deleteAtDesiredPosition()
{
    int userNode;
    puts("\nwrite the node number to delete:");
    scanf("%d", userNode);
    fflush(stdin);

    int totalNodes = totalNodeInList();
    if (userNode > totalNodes || userNode < 1)
    {
        printf("Invalid node number entered........\n");
        return;
    }
    int positionOfStart = currentPositionOfStart();

    if (positionOfStart > userNode)
    {
        while (1)
        {
            start = start->prv;
            if (--positionOfStart == userNode)
                break;
        }
    }
    else if (positionOfStart < userNode)
    {
        while (1)
        {
            start = start->next;
            if (++positionOfStart == userNode)
                break;
        }
    }

    // linking then deleting
    start->prv->next = start->next;
    printf("Node number %d (Name = %s & Wage =%d) deleted successfully.........\n\n", userNode, start->name, start->wage);
    free(start);
    start = top; // now start will not pointing any node of list. So, we have assigned address of 1st node to 'start'. So,It will pointed in list.
}

/*----------------DISPLAY OPERATIONS--------------------*/
/*to display the menu of displaying the linked list */
void displayMenu()
{
    puts("\nPress 1 to display from beginning.");
    puts("Press 2 transverse the list from end.");
    int choice;
    scanf("%d", &choice);
    fflush(stdin);

    switch (choice)
    {
    case 1:
        displayFromBeginning();
        break;
    case 2:
        break;
    default:
        puts("wrong choice selected.");
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
        int counter = 0;     // for counter the node number in printing
        while (temp != NULL) // temp->prv!=NULL will not work for 1st node
        {
            printf("\n=============Node Number %d============\n", ++counter);
            printf("-> %d %s\n", temp->wage, temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

/*-----------------SEARCH OPERATIONS--------------------*/
/* to search the data from linked list*/
void searchDataMenu() {}