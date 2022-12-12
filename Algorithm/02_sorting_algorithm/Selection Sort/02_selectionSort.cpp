/*selection sort using two ways.
 *1. swapping perform in inner for loop each time if condition is true.
 *2. swapping perform just after termination of inner loop.
 */

/*
 *author: Suraj Kumar Giri.
 *Date: 15-03-2022
 *Time: 04:45:30
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

/*for sorting the array using selection sort*/
class selectionSort
{
    int *array;
    int size;
    void creatArray();
    void algorithm1();
    void algorithm2();
    void displaySortedArray();

public:
    void sortTheArray(int choice)
    {
        creatArray();
        if (choice == 1)
        {
            algorithm1();
        }
        else
            algorithm2();
        displaySortedArray();
        free(array); // free memory
    }
};

/*to create the array dynamically*/
void selectionSort::creatArray()
{
    cout << "write the size of array:" << endl;
    fflush(stdin);
    cin >> size;
    array = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        cout << "write number of index " << i << ":" << endl;
        cin >> array[i];
    }
}

/*sorting using selection sort. By swapping outside the inner for loop.*/
void selectionSort::algorithm1()
{

    for (int i = 0; i < size - 1; i++)
    {
        int minimum = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[minimum] > array[j])
                minimum = j;
        }

        if (i != minimum) // it's (only if statement) not compulsory. But O(1) (in case of array[i] is smallest) is better than O(4).
        {
            /*It's working*/
            // int temp = array[i];
            // array[i] = array[minimum];
            // array[minimum] = temp;

            /*we can use the below code also. Both working*/
            int temp = array[minimum];
            array[minimum] = array[i];
            array[i] = temp;
        }
    }
}

/*sorting using selection sort. By swapping inside the inner for loop.*/
void selectionSort::algorithm2()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j]) // performing swapping
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

/*to display the sorted array*/
void selectionSort::displaySortedArray()
{
    cout << "Sorted Array is following:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
}

int main()
{
    system("cls");
    selectionSort obj;
    cout << "Press 1 for sort the array via algorithm 1 of selection i.e swapping in inner loop." << endl;
    cout << "Press 2 for sort the array via algorithm 2 of selection i.e swapping outside of inner loop." << endl;
    int choice = 1;
    cout << "$ ";
    cin >> choice;
    if (choice < 1 || choice > 2)
        obj.sortTheArray(1);
    else
        obj.sortTheArray(choice);
    return 0;
}
