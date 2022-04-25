#include <stdio.h>
#include <stdlib.h>
struct node
{
    char name[30];
    int roll;
    struct node *link;
} * start; // it's global so auto initialized with 0

void create_node();
void display();
int main()
{
    int choice;
    do
    {
        puts("\nPress 1 for create a new node:");
        puts("Press 2 for display the existing linked list:");
        puts("Press 3 for exit:");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            create_node();
            break;

        case 2:
            display();
            break;
        } // end of switch
    } while (choice != 3);
    return 0;
}

void create_node() // it creates one node in each call
{
    // creating a random node anywhere
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    struct node *temp; // helps in checking existing node by taking start's address first time
    printf("write name of student:\n");
    gets(new_node->name);
    printf("write roll of student:\n");
    scanf("%d", &new_node->roll);
    new_node->link = NULL;

    // now adding the random node to linked list (if linked list not existing then we create and add)
    temp = start; // temp store address of existing node every time and helps in checking the NULL
    // now adding the node that is taken above to the linked list (create if not exist else add in existing
    if (start == NULL) // only in first call means no node exist before it.
        start = new_node;
    else
    {
        while (1)
        {
            if (temp->link == NULL)
            {
                // temp = new_node;//error
                temp->link = new_node;
                break;
            }
            else
                temp = temp->link;
        }
    }
    puts("Node created successfully\n");
}

void display()
{
    struct node *ptr = start;
    while (1)
    {
        if (ptr == NULL)
        {
            if (ptr == start) // only execute if start is null means linked list not exist
                printf("Linked list not exist.\n\n");
            break;
        }
        else
        {
            printf("%d => %s\n", ptr->roll, ptr->name);
            ptr = ptr->link;
        }
    }
}