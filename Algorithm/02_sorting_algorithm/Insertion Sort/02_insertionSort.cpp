/*Insertion sort using cpp*/
/*
 *author: Suraj Kumar Giri.
 *Date: 03-04-2022
 *Time: 22:52:39
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

/* to perform all the operations of insertion sort on array */
class insertionSort
{
    int size;
    int *array;
    void inputArray();
    void performInsertionSort();
    void display();

public:
    void sortMyArray()
    {
        inputArray();
        performInsertionSort();
        display();
        free(array); // free the allocated memory
    }
};

/*take the input in array from user*/
void insertionSort::inputArray()
{
    cout << "How many numbers do you want to input:" << endl;
    cin >> size;
    array = (int *)calloc(size, sizeof(int)); // allocating memory

    for (int i = 0; i < size; i++)
    {
        cout << "write the number for index " << i << endl;
        cin >> *(array + i);
    }
}

/*sort the array using insertion sort algorithm*/
void insertionSort::performInsertionSort()
{
    for (int i = 1; i < size; i++)
    {
        int j;
        int temp = array[i];
        for (j = i - 1; array[j] > temp && j >= 0; j--)
            array[j + 1] = array[j];
        array[j + 1] = temp;
    }
}

/*to display the sorted array*/
void insertionSort::display()
{
    cout << "\n====SORTED ARRAY ARE FOLLOWING=====" << endl;
    for (int i = 0; i < size; i++)
        cout << *(array + i) << " ";
}

int main()
{
    system("cls");
    insertionSort obj;
    obj.sortMyArray();
    return 0;
}