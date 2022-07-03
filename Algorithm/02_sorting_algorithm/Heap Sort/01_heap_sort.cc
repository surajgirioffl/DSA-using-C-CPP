/*heap sort*/
/**
 *author: Suraj Kumar Giri.
 *Date: 17-05-2022
 *Time: 09:18:45
 */

#include <iostream>
#include <stdlib.h>
using namespace std;
bool isArraySorted(int *array, int length);

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
        /*we will use bottom-up approach to arrange the heap from scratch*/
        for (int lastParentIndex = sizeOfArray / 2; lastParentIndex >= 1; lastParentIndex--)
            arrangeInHeap(lastParentIndex);

        /*        now deleting the elements of the array*/
        for (int i = 1; i <= max; i++)
        {
            int root = deleteRoot();
            array[sizeOfArray + 1] = root; // assigning the max element in last of array (we have decreased it by 1 in deleteRoot() function. so, here we assinging after increasing by 1)
        }
        display();
        if (isArraySorted(array, max + 1))
            cout << "\n\033[1;32mSORTED\033[0m" << endl;
        else
            cout << "\n\033[1;31mNOT SORTED\033[0m" << endl;
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
        /*swapping*/
        int temp = array[leftChildIndex];
        array[leftChildIndex] = array[parentIndex];
        array[parentIndex] = temp;
    }
}

void heapSortClass::inputArray()
{
    short changer = 4;
    for (int i = 1; i <= sizeOfArray; i++)
    {
        cout << "write element of index " << i << " = ";
        // cin >> array[i];
        array[i] = 100 - (i * changer);
        cout << *(array + i) << endl;
    }
}

void heapSortClass::display()
{
    cout << "\nShorted array are following:" << endl;
    for (int i = 1; i <= max; i++)
        cout << array[i] << " ";
}

int main()
{
    system("cls");
    heapSortClass obj;
    obj.heapSort();
    return 0;
}

/*returns true if sorted else returns false;*/
bool isArraySorted(int *array, int length)
{
    bool isSorted = true; // to check that array is already sorted or not
    // on the basis of insertion sort
    // let i=0 is already sorted but here in heap sort we deal with array from index 1. So, i=1+1=2;
    for (int i = 2; i < length; i++)
    {
        int minimum = array[i];
        int j;
        for (j = i - 1; j >= 1 && array[j] > minimum; j--)
        {
            /*compiler will never enter in this block when our data of array will already sorted.*/
            isSorted = false;
            array[j + 1] = array[j];
            // break; // we will break the loop because our problem is solved.
        }
        array[j + 1] = minimum;
        // if (!isSorted)
        //     break;
    }
    if (isSorted) // isSorted will contains 'true' if data is already sorted else false
        return true;
    return false; // unsorted
}