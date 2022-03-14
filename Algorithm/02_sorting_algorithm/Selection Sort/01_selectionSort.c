/*selection Sort Algorithm*/
#include <stdio.h>
#define MAX 10

/*sort array in ascending order using selection sort algorithm*/
void sortArrayAscending(int *array)
{
    /*
     * in ascending, number starts from smallest to largest
     */
    for (int i = 0; i < MAX - 1; i++)
    {
        int smallerNoIndex = i; // to store the index of number smaller than current number i.e temp
        // we have initialized 'smallerIndex' because if condition not satisfied in any iteration of inner for loop then the require position of number will remain same.

        for (int j = i + 1; j < MAX; j++)
        {
            if (array[smallerNoIndex] > array[j])
                smallerNoIndex = j;
        }
        // now, swapping
        int temp = array[i];
        array[i] = array[smallerNoIndex];
        array[smallerNoIndex] = temp;
    }
}

/*sort array in descending order using selection sort algorithm*/
void sortArrayDescending(int *array)
{
    for (int i = 0; i < MAX - 1; i++)
    {
        int greaterNoIndex = i;
        for (int j = i + 1; j < MAX; j++)
        {
            if (array[greaterNoIndex] < array[j])
                greaterNoIndex = j;
        }
        // swaping now
        int temp = array[i];
        array[i] = array[greaterNoIndex];
        array[greaterNoIndex] = temp;
    }
}

/*take array from user*/
void inputArray(int *array)
{
    for (int i = 0; i < MAX; i++)
    {
        printf("Write element of index %d\n", i);
        scanf("%d", &array[i]);
    }
}

int main()
{
    int array[MAX];
    inputArray(array);
    sortArrayAscending(array);
    puts("\nSorted Array (Ascending) is following :");
    for (int i = 0; i < MAX; i++)
        printf("\t%d", array[i]);

    sortArrayDescending(array);
    puts("\nSorted Array (Descending) is following :");
    for (int i = 0; i < MAX; i++)
        printf("\t%d", array[i]);
    return 0;
}