/*sorting single unsorted array using merge sort*/
/*it's nothing but merging of two sorted array in last step*/

#include <iostream>
using namespace std;

class mergeSort
{
    int *array;
    int size;
    int *tempArray; // store the array while merging temporarily
    void inputArray();
    void divide(int low, int high);
    void merge(int low1, int high1, int low2, int high2);
    void display();

public:
    void sortMyArray()
    {
        cout << "write the size of array:" << endl;
        cin >> size;
        array = (int *)calloc(size, sizeof(int));
        tempArray = (int *)calloc(size, sizeof(int));
        inputArray();
        divide(0, size - 1);
        display();
        free(array);     // free the allocated memory of heap
        free(tempArray); // free the  allocated memory
    }
};

/*input array from user*/
void mergeSort::inputArray()
{
    for (int i = 0; i < size; i++)
    {
        cout << "write the of index " << i << " :" << endl;
        cin >> *(array + i);
    }
}

/*divide the array and after complete dividing call the merge function*/
void mergeSort::divide(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        divide(low, mid);
        divide(mid + 1, high);
        merge(low, mid, mid + 1, high); // just merge like sorted two arrays
    }
}

void mergeSort::merge(int low1, int high1, int low2, int high2)
{
    int i = low1; // for 1st sorted part or for 1st sorted array
    int j = low2; // for 2nd sorted part or for 2nd sorted array
    int k = low1; // for index of tempArray

    while (i <= high1 && j <= high2)
    {
        if (array[i] < array[j])
            tempArray[k++] = array[i++];
        else
            tempArray[k++] = array[j++];
    }
    // if any of both part/sorted array have more elements than 2nd one.
    /*one while of below two's will execute if(low1!=high1)*/
    while (i <= high1)
        tempArray[k++] = array[i++];
    while (j <= high2)
        tempArray[k++] = array[j++];

    // now adding the sorted data in main array
    for (i = low1; i < k; i++)
        array[i] = tempArray[i];
}

/*display the sorted array*/
void mergeSort::display()
{
    cout << "\n====SORTED ARRAY ARE FOLLOWING=====" << endl;
    for (int i = 0; i < size; i++)
        cout << *(array + i) << " ";
}

int main()
{
    system("cls");
    mergeSort obj;
    obj.sortMyArray();
    return 0;
}