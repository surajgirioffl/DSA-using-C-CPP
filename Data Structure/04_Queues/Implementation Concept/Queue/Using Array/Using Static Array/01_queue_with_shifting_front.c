/*Queue using static array with function.
 *Operation using integer data type.
 *with shifting of the front
 *with local front and rear of main()
 */

/* limitations of shifting of front.
 * if we delete the element then that block can't be filled with new element.
 * space will remaining but we can't insert element after deletion (after one complete overflow).
 */

/*Logic behind the queue overflow and underflow.
 * For underflow (empty) -> front==-1 or front==rare+1
 * For overflow (Full) -> rear = MAX-1
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10 // for storing 10 numbers using static array

void insert(int *queue, int *rear, int *front);
void delete (int *queue, int rear, int *front);
void display(int *queue, int rear, int front);
void peek(int *queue, int front, int rear);
int isEmpty(int rear, int front);
int isFull(int rear);

int main()
{
    int front = -1;
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
            insert(queue, &rear, &front);
            break;
        case 2:
            delete (queue, rear, &front);
            break;
        case 3:
            peek(queue, front, rear);
            break;
        case 4:
            display(queue, rear, front);
            break;
        case 5:
            exit(1);
        default:
            puts("wrong choice selected.");
        } /*end of switch */
        system("pause");
        system("cls");
    } /*end of while */

} /*end of main*/

/*To insert element in queue.
 * insertion will be performed using 'rear'. so, we have taken it by reference.
 * 'front' is taken using reference because in first call i.e when queue is empty then we have to increase the front.
 */
void insert(int *queue, int *rear, int *front)
{
    if (isFull(*rear)) // bug fixed. we have to send the value after dereferencing the pointer
        puts("Queue is full. Overflow.");
    else
    {
        if ((*front) == -1) // only when first element will inserted in queue.
            (*front)++;     // i.e front = 0;

        (*rear)++;
        puts("write integer to insert at end:");
        scanf("%d", &queue[*rear]);
    }
} /*end of insert()*/

/* to delete the element of the queue using shifting of index*/
void delete (int *queue, int rear, int *front)
{

    if (isEmpty(rear, *front))
        puts("Queue is empty.");
    else
    {
        printf("Removed element is peek element which is %d.\n", queue[*front]);
        (*front)++; // shifting to next index
    }
} /*end of delete()*/

/*to display the contents of the queue*/
void display(int *queue, int rear, int front)
{
    if (isEmpty(rear, front))
        puts("Queue is empty. Underflow.");
    else
    {
        puts("Queue's contents are following:");
        for (front; front <= rear; front++) // if we don't use shifting then front will always pointing to index 0
            printf("%d ", queue[front]);
        printf("\n");
    }
} /*end of display()*/

/*To print the front element of the queue.
 * 'rear' and 'front' will help in checking underflow of queue.
 *variable by reference is not required because we haven't to change anything
 */
void peek(int *queue, int front, int rear)
{
    if (isEmpty(rear, front))
        puts("Queue is empty. Underflow");
    else
        printf("The peek element is %d.\n", queue[front]);
    /*It will simply print the front element of the queue*/
} /*end of peek()*/

/*returns 1 if queue is empty else 0 otherwise*/
int isEmpty(int rear, int front)
{
    if (front == -1 || front == (rear + 1))
        return 1;
    return 0;
} /*end of isEmpty()*/

/*returns 1 if full else return 0*/
int isFull(int rear)
{
    if (rear == MAX - 1)
        return 1;
    return 0;
} /*end of isFull()*/