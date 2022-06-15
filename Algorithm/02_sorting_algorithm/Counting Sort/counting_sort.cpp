#include <bits/stdc++.h>
using namespace std;
class countingSort
{
    int *array; // original array
    int length; // length of original array

    /*to input the array elements*/
    void inputArray()
    {
        cout << "write the length of the array:" << endl;
        cin >> length;
        array = new int[length];

        for (int i = 0; i < length; i++)
        {
            cout << "write the value for index " << i << ":" << endl;
            cin >> *(array + i);
        }
    }

    /*returns max element of the array*/
    short maxElement()
    {
        int max = array[0];
        for (int i = 0; i < length; i++)
            if (array[i] > max)
                max = array[i];
        return max;
    }

    /*initialize array with 0*/
    void arrayInitializer(int *array, int length)
    {
        for (int i = 0; i < length; i++)
            array[i] = 0;
    }

    /*Display sorted array*/
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            if (i == 0)
                cout << endl
                     << "shorted array is following:" << endl;
            cout << array[i] << ends;
        }
    }

public:
    void sort()
    {
        inputArray();
        int *counterArray;
        int length = maxElement() + 1; //+1 because we also need maxElement as index in counterArray //local variables have more priority. So, this 'length' variable will be used here
        counterArray = new int[length];
        arrayInitializer(counterArray, length);

        /*
         *index of counterArray = Value in main array
         *value in counterArray = number of times the index of counterArray repeated in main array
         *In below for loop in counterArray we are assigning the number of times a value appears in main array
         */
        for (int i = 0; i < this->length; i++)
            counterArray[array[i]]++;

        /*now copying the element to main array with it's proper position */
        for (int i = 0, j = 0; i < length; i++)
        {

            if (counterArray[i] == 0)
                continue;
            while (counterArray[i] > 0)
            {
                array[j++] = i;
                counterArray[i]--;
            }
        }
        display();
        /*releasing of memory*/
        delete[] counterArray;
        delete[] array;
    }
};

int main(void)
{
    cout << "\033[2J\033[H";
    countingSort obj;
    obj.sort();
}