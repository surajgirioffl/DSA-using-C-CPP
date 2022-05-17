/*heap sort*/
/**
 *author: Suraj Kumar Giri.
 *Date: 17-05-2022
 *Time: 09:18:45
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

class heapSortClass
{
    int sizeOfArray;
    int *array;
    int max; // to save the size of the array
    void inputArray();
    void display();
    void arrangeInHeap(int);
    int deleteRoot();

public:
    /*returns true on success else false on failure*/
    bool heapSort()
    {
        cout << "write the size of array:" << endl;
        cin >> sizeOfArray;
        max = sizeOfArray;                                   // to save the size of the array
        array = (int *)calloc(sizeOfArray + 1, sizeof(int)); //+1 because here we will start array from index 1. 4 bytes of memory will be lost. We will think on it later.
        inputArray();
        /*first we need to create a heap of the array*/
        /*we will use buttom-up approach to arrange the heap from scratch*/
        for (int lastParentIndex = sizeOfArray / 2; lastParentIndex >= 1; lastParentIndex--)
            arrangeInHeap(lastParentIndex);

        /*        now deleting the elements of the array*/
        for (int i = 1; i <= max; i++)
        {
            int root = deleteRoot();
            array[sizeOfArray + 1] = root; // assigning the max element in last of array (we have decreased it by 1 in deleteRoot() function. so, here we assinging after increasing by 1)
        }
        display();
        return true;
    }
    /*constructor*/
    heapSortClass(void)
    {
        sizeOfArray = 0;
    }
};

int heapSortClass::deleteRoot()
{
    int rootMax = array[1];
    /*assigning last element of heap to 1st*/
    array[1] = array[sizeOfArray];
    sizeOfArray--; // after deleting the root.
    /*arranging heap in top-down approach*/
    arrangeInHeap(1); // 1 is parent index which is need to be arranged to follow heap properties
    return rootMax;
}

void heapSortClass::arrangeInHeap(int parentIndex)
{
    int leftChildIndex = parentIndex * 2;
    int rightChildIndex = leftChildIndex + 1;
    while (rightChildIndex <= sizeOfArray) // satisfied only if both child exist
    {
        /*Three case are possible
         *parent will greater or equal to that both child means no need to swap.
         *parent will be greater than left child
         *parent will be greater than right child
         */
        int parent = array[parentIndex];
        if (parent >= array[leftChildIndex] && parent >= array[rightChildIndex])
        { // no need to swap. No further arrangement
            return;
        }
        else if (parent < array[leftChildIndex])
        {
            array[parentIndex] = array[leftChildIndex];
            array[leftChildIndex] = parent;
            parentIndex = leftChildIndex;
        }
        else // means parent<array[rightChildIndex]
        {
            array[parentIndex] = array[rightChildIndex];
            array[rightChildIndex] = parent;
            parentIndex = rightChildIndex;
        }

        /*in case level of node is less that height - 2*/
        /*means arranging as above the data may change and heap properties may hamper for child who is parent*/
        /*we will arrange for only those node which is changed by above lines of code*/
        leftChildIndex = parentIndex * 2;
        rightChildIndex = leftChildIndex + 1;
    }
    if (leftChildIndex == parentIndex && array[leftChildIndex] > array[parentIndex]) // In last level at last position if only left child exist
    {
        /*swaping*/
        int temp = array[leftChildIndex];
        array[leftChildIndex] = array[parentIndex];
        array[parentIndex] = temp;
    }
}

void heapSortClass::inputArray()
{
    for (int i = 1; i <= sizeOfArray; i++)
    {
        cout << "write element of index " << i << endl;
        cin >> array[i];
    }
}

void heapSortClass::display()
{
    cout << "\nShorted array are following:" << endl;
    for (int i = 1; i < max; i++)
        cout << array[i] << " ";
}

int main()
{
    system("cls");
    heapSortClass obj;
    obj.heapSort();
    return 0;
}