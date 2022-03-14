/*Bubble sort algorithm*/
#include <stdio.h>
#define MAX 10
void sortArrayAscending(int array[]);
void sortArrayDescending(int *array);
int main()
{
    int array[MAX];
    for (int i = 0; i < MAX; i++)
    {
        printf("Write element of index %d\n", i);
        scanf("%d", &array[i]);
    }

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

/*
 * bubble sort algorithm (Ascending).
 * we can use int* in formal argument here but in debugging only 1 data will shown because pointer points to only one address at a time.
 * so, we have user array[] and it will show all elements at the same time
 * but it would not work because either we use array[] or int* array. in both case only base address pass. and works like int*.
 */
void sortArrayAscending(int array[])
{
    int temp;
    for (int i = 0; i < MAX - 1; i++) // loop for pass
    {
        for (int j = 0; j < (MAX - 1) - i; j++) // loop for sorting one element in each iteration
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

/*bubble sort algorithm (Descending)*/
void sortArrayDescending(int *array)
{
    int temp;
    for (int i = 0; i < MAX - 1; i++) // loop for pass
    {
        for (int j = 0; j < (MAX - 1) - i; j++) // loop for sorting one element in each iteration
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
