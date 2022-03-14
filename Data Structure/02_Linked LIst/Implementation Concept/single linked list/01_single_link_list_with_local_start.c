/*Single Linked List all operations Using Local 'start' variable*/
/*
 *author: Suraj Kumar Giri.
 *Date: 22-02-2022
 *Time: 10:00:17
 */
#include <stdio.h>
#include <stdlib.h>
struct libraryBooks
{
    char bookName[40];
    int price;
    struct libraryBooks *next; // pointer to next node
};

typedef struct libraryBooks lBook;

lBook *createNode();
lBook *insertBookAtEnd(lBook *start);
int isNotExist(lBook *start);
void displayBook(lBook *start);

/*main() function*/
int main()
{
    lBook *start = NULL;
    int choice;
    do
    {
        puts("Press 1 to insert a node at end.");
        puts("Press 2 to display the linked list from beginning.");
        puts("Press 3 to clear screen.");
        puts("Press 4 to exit.");
        printf("$ ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            start = insertBookAtEnd(start);
            break;
        case 2:
            displayBook(start);
            break;
        case 3:
            system("cls");
            break;
            // default:
            //     puts("wrong choice selected.");
        }
    } while (choice != 4);
}

/*create a random node pointing anywhere and returns it's address*/
lBook *createNode()
{
    lBook *newNode = (lBook *)malloc(sizeof(lBook));
    puts("write name of book:");
    gets(newNode->bookName);
    puts("write price:");
    scanf("%d", &newNode->price);
    fflush(stdin);
    newNode->next = NULL; // It's compulsory because next of last node will be NULL.
    return newNode;
}

/*insert a newNode at end of linked list. If linked list doesn't exist then it will create. Returns 'start'.*/
lBook *insertBookAtEnd(lBook *start)
{
    lBook *temp = createNode(); // to store the address of newly created node.
    lBook *ptr = start;         // to transverse in linked list. We have used this because we can't change the start.
    if (start == NULL)
        start = temp;
    else
    {
        /*
         *we have to transverse a pointer to last node. So, we can insert after it.
         *so, we have used while() loop to point the 'ptr' to last node
         */
        while (ptr->next != NULL)
            ptr = ptr->next; // transversing forward in linked list

        // now original operation of linking will performed
        ptr->next = temp;
    }
    puts("Data inserted successfully...");
    return start;
}

/*returns 1 if linked list not exists, 0 otherwise*/
int isNotExist(lBook *start)
{
    if (start == NULL)
        return 1;
    return 0;
}

/*Display the linked list from beginning*/
void displayBook(lBook *start)
{
    if (isNotExist(start))
        puts("Linked list doesn't exist.");
    else
    {
        lBook *temp = start; // to transverse and print the info of node.
        while (temp != NULL)
        {
            printf("%s\t%d\n", temp->bookName, temp->price);
            temp = temp->next;
        }
    }
    printf("\n");
}