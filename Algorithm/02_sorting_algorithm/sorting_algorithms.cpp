/*
 *Sorting (Ascending) algorithms using c++.
 *Bubble sorting algorithm
 *Selection Sort algorithm
 *Insertion Sort algorithm
 *Merge Sort algorithm
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

class sorting
{
    void menu();
    void inputArray();
    int *array;
    int sizeOfArray; // take size of array from user.
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void display();

public:
    void sortMyArray()
    {
        while (true)
        {
            menu();
            free(array);
        }
    }
};

/*sort the array using bubble sort algorithm*/
void sorting::bubbleSort()
{
    for (int i = 0; i < sizeOfArray - 1; i++)
    {
        for (int j = 0; j < sizeOfArray - i - 1; j++)
        {
            /*now shifting the bigger number to right side*/
            /*in each iteration of i, one number will sorted and shift to right*/
            if (array[j] > array[j + 1])
            {
                /*performing swaping*/
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

/*sort the array using selection sort algorithm*/
void sorting::selectionSort()
{
    for (int i = 0; i < sizeOfArray - 1; i++)
    {
        int index = i; // to store the index of smallest number
        for (int j = i + 1; j < sizeOfArray - 1; j++)
        {
            if (array[index] > array[j])
                index = j;
        }
        // now after inner for loop. 'index' have index of lowest data
        if (i != index)
        {
            // swaping
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
    }
}

/*sort the array using insertion sort algorithm*/
void sorting::insertionSort()
{
    // let first element of array is already sorted. So, i started with 1
    for (int i = 1; i < sizeOfArray; i++)
    {
        int temp = array[i];
        int j;
        for (j = i - 1; array[j] > array[i] && j > 0; j--)
            array[j + 1] = array[j];
        array[j + 1] = temp; // because when loop terminates j would already 1 less.
    }
}

void sorting::display()
{
    cout << "\n=====SORTED ARRAY IS FOLLOWING=========" << endl;
    for (int i = 0; i < sizeOfArray; i++)
        cout << array[i] << "\t";
    cout << endl;
    system("pause");
}

/*take input of array from user and store it dynamically*/
void sorting::inputArray()
{
    cout << "write the size of array:" << endl;
    cin >> sizeOfArray;
    array = (int *)calloc(sizeOfArray, sizeof(int));
    for (int i = 0; i < sizeOfArray; i++)
    {
        cout << "write number of index " << i << " :" << endl;
        cin >> array[i];
    }
}

/*display the menu to user and take his/her choice and call the deserired function to fulfill the user needs*/
void sorting::menu()
{
    cout << "\nPress 1 for sort the array using Bubble Sort" << endl;
    cout << "Press 2 for sort the array using Selection Sort" << endl;
    cout << "Press 3 for sort the array using Insertion Sort" << endl;
    cout << "Press 11 for clear the display" << endl;
    cout << "Press 12 for exit the program" << endl;

    int choice;
    puts("\nWrite your choice from above:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        inputArray();
        bubbleSort();
        display();
        break;
    case 2:
        inputArray();
        selectionSort();
        display();
        break;
    case 3:
        inputArray();
        insertionSort();
        display();
        break;
    case 11:
        system("cls");
        break;
    case 12:
        exit(1);
        break;
    }
}

int main()
{
    system("cls");
    sorting obj;
    obj.sortMyArray();
    return 0;
}