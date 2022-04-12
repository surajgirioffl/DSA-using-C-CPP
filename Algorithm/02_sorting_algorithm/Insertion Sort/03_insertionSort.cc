#include <iostream>
using namespace std;
class insertionSort
{
    short size;
    short *array;
    void display();
    void performInsertionSort();

public:
    void sortMyArray()
    {
        performInsertionSort();
        display();
        free(array);
    }
};

void insertionSort::display()
{
    cout << "\n====SORTED ARRAY ARE FOLLOWING=====" << endl;
    for (int i = 0; i < size; i++)
        cout << *(array + i) << " ";
}

void insertionSort::performInsertionSort()
{
    cout << "write the size of the array" << endl;
    cin >> size;
    array = (short *)calloc(size, sizeof(short));
    cout << "write element of index 0" << endl;
    cin >> *array;
    for (short i = 1; i < size; i++)
    {
        cout << "write element of index " << i << endl;
        cin >> *(array + i);
        short temp = *(array + i);
        short j;
        for (j = i - 1; array[j] > temp && j >= 0; j--)
            array[j + 1] = array[j];
        array[j + 1] = temp;
    }
}

int main()
{
    system("cls");
    insertionSort obj;
    obj.sortMyArray();
    return 0;
}