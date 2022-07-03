/*Queue using structure array without shifting front*/
/*we will perfrom operation by shifting the rear*/

/*logic
 *for full: rear=MAX-1
 *for empty: front=-1 or rear=-1 (we will only use one of 2 here to check but in linked list implementation we have to use both)
 */

/*
 *author: Suraj Kumar Giri.
 *Date: 12-02-2022
 *Time: 08:02:53
 */
#include <stdlib.h>
#include <stdio.h>
#define MAX 5
struct labor
{
    char *name;
    int wage;
};
typedef struct labor labor;
void insert(labor *queue, int *rear);
void delete (labor *queue, int *rear);
void display(labor *queue, int rear);
void peek(labor *queue, int rear);
int isEmpty(int rear);
int isFull(int rear);

int main()
{
    // int front = -1;
    int rear = -1;
    labor queue[MAX]; // taking array of structure to store multiple data
    while (1)
    {
        puts("Press 1 to insert.");
        puts("Press 2 to delete.");
        puts("Press 3 to display peek element.");
        puts("Press 4 to display the queue.");
        puts("Press 5 to exit.");
        printf("$ ");
        int choice;
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            insert(queue, &rear);
            break;
        case 2:
            delete (queue, &rear);
            break;
        case 3:
            peek(queue, rear);
            break;
        case 4:
            display(queue, rear);
            break;
        case 5:
            exit(1);
        default:
            puts("wrong choice selected.");
        } /*end of switch */
        system("pause");
        system("cls");
    } /*end of while */
    return 0;
}

void insert(labor *queue, int *rear)
{
    if (isFull(*rear))
        puts("Queue is full. Overflow");
    else
    {
        (*rear)++;
        queue[*rear].name = (char *)calloc(30, sizeof(char));
        printf("write labor name:\n");
        gets(queue[*rear].name);
        printf("write wage of %s:\n", queue[*rear].name);
        scanf("%d", &queue[*rear].wage);
    }
}

void delete (labor *queue, int *rear)
{
    if (isEmpty(*rear))
        puts("Queue is empty.");
    else
    {
        // deletion operation always performed from front in single ended queue
        printf("Deleted element is %s %d.\n", queue[0].name, queue[0].wage);
        for (int i = 0; i < (*rear); i++)
            queue[i] = queue[i + 1]; // shifting towards front
        (*rear)--;
    }
}

void display(labor *queue, int rear)
{
    if (isEmpty(rear))
        puts("Queue is empty.");
    else
    {
        puts("Queue elements are following:");
        for (int i = 0; i <= rear; i++)
            printf("->%s %d  ", queue[i].name, queue[i].wage);
        printf("\n");
    }
}

void peek(labor *queue, int rear)
{
    if (isEmpty(rear))
        puts("Queue is empty.");
    else
        printf("Peek element is : %s %d.\n", queue[rear].name, queue[rear].wage);
}

/*returns 1 if queue is empty 0 otherwise*/
int isEmpty(int rear)
{
    if (rear == -1)
        return 1;
    return 0;
}

/*returns 1 if queue is full, 0 otherwise */
int isFull(int rear)
{
    if (rear == MAX - 1)
        return 1;
    return 0;
}