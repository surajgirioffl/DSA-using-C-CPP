/*
 *author: Suraj Kumar Giri.
 *Date: 15-02-2022
 *Time: 10:00:31
 */

/*Insertiona and deletion operations can be performed from both ends*/

/*
 *Conditions of empty of queue:-
 *1. when front or rear == -1
 *there are more conditions but we will not create that condition just by 'when the last element of queue will deleted then both the front and the rear reset to -1.
 */

/*
 *Conditions of queue overflow:-
 *1. when front = 0 && rear == MAX-1
 *2. when front = rear + 1
 *there are more conditions but we will not create that condition just by 'when the last element of queue will deleted then both the front and the rear reset to -1.
 */

/*
 *Extra operations performed in deque is same as circular queue and sime linear queue
 *1. Assign (reset the value to) front=rear=-1, when last element of queue will be deleted
 *2. Assign front= rear=0, when 1st element is inserted i.e when rear=front=-1
 *3. During Insertion from front end:
 *   ->Assign front=front-1 then insert at this front.
 *   ->and if front=0 then assign front=Max-1
 *4. During deletion from front end:
 *   ->Assign front=front+1.
 *   ->and if front=MAX-1 then assign front=0;
 *5. During insertion from rear end:
 *   ->Assign rear=rear+1 then insert at this rear.
 *   ->and if rear=Max-1 then assign rear=0
 *6. During deletion from rear end:
 *   ->Assign rear=rear-1
 *   -> if rear=0 then assign rear=Max-1
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void isFull();
void isEmpty();
