/*insertion Sort Algorithm*/
#include <stdio.h>
#define MAX 10

/*sort array in ascending order using insertion sort algorithm*/
void sortArrayAscending(int *array)
{
    // we assume that 1st element of array is already sorted
    for (int i = 1; i < MAX; i++)
    {
        int j = i - 1;
        int temp = array[i];
        while (array[j] > temp && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

/*sort array in descending order using insertion sort algorithm*/
void sortArrayDescending(int *array)
{
    // we assume that 1st element of array is already sorted
    for (int i = 1; i < MAX; i++)
    {
        int temp = array[i];
        int j;
        for (j = i - 1; j >= 0 && array[j] < temp; j--)
            array[j + 1] = array[j];
        array[j + 1] = temp; // because on termination of loop j decrease by 1
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
    printf("\n");
    return 0;
}