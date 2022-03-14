/*Queue using static array with function.
 *Operation using integer data type.
 *without shifting of front
 *with local front and rear of main()
 */

/* limitations of shifting of front.
 * In each deletion the whole array elements are shifted and processing increase too much.
 * Time complexity become O(n) i.e we have to execute the loop for each element.
 * /

/*Logic behind the queue overflow and underflow.
 * For underflow (empty) -> front==-1 or rear ==-1
 * For overflow (Full) -> rear = MAX-1
 */
/* after insertion front always = 0*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void insert(int *queue, int *rear);
void delete (int *queue, int *rear);
void display(int *queue, int rear);
void peek(int *queue, int rear);
int isEmpty(int rear);
int isFull(int rear);

int main()
{
    // int front = -1;
    int rear = -1;
    int queue[MAX];
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

void insert(int *queue, int *rear)
{
    if (isFull(*rear))
        puts("Queue is full. Overflow");
    else
    {
        (*rear)++;
        printf("write number:\n");
        scanf("%d", &queue[*rear]);
    }
}

void delete (int *queue, int *rear)
{
    if (isEmpty(*rear))
        puts("Queue is empty.");
    else
    {
        printf("Deleted element is %d.\n", queue[0]); // 0 means front element
        for (int i = 0; i < (*rear); i++)
            queue[i] = queue[i + 1];
        (*rear)--;
    }
}

void display(int *queue, int rear)
{
    if (isEmpty(rear))
        puts("Queue is empty.");
    else
    {
        puts("Queue elements are following:");
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

void peek(int *queue, int rear)
{
    if (isEmpty(rear))
        puts("Queue is empty.");
    else
        printf("Peek element is : %d.\n", queue[rear]);
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