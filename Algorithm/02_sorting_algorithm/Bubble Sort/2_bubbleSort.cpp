/*bubble sort algorithm using c++*/
#include <iostream>
#include <stdlib.h>
using namespace std;

class bubbleSort
{
    int *array; // to store the array
    short size; // for size of array taken by user
    void inputArray();
    void sortArrayAscending();
    void sortArrayDescending();
    void displayData();

public:
    void sortNumber()
    {
        inputArray();
        sortArrayAscending();
        cout << "Sorted Array in ascending order is following:" << endl;
        displayData();
        sortArrayDescending();
        cout << "\nSorted Array in descending order is following:" << endl;
        displayData();
        free(array); // freeing the allocated memory
    }
};

/*take array from user (use dynamic memory allocation)*/
void bubbleSort::inputArray()
{
    cout << "write the size of array that you want:" << endl;
    cin >> size;
    array = (int *)calloc(size, sizeof(int));

    // now taking elements of array from user
    for (int i = 0; i < size; i++)
    {
        cout << "write element of index " << i << " : ";
        cin >> array[i];
    }
}

/*sort the array in ascending order using bubble sort algorithm*/
void bubbleSort::sortArrayAscending()
{
    int temp; // to store the data temporarily
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

/*sort the array in descending order using bubble sort algorithm*/
void bubbleSort::sortArrayDescending()
{
    int temp; // to store the data temporarily
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] < array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

/*to display the array*/
void bubbleSort::displayData()
{
    for (int i = 0; i < size; i++)
        cout << "\t" << array[i];
}

/*main function*/
int main()
{
    bubbleSort obj;
    obj.sortNumber();
    return 0;
}