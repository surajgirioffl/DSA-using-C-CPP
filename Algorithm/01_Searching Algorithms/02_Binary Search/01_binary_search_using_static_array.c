/*Binary search using static array*/

/*
 *author: Suraj Kumar Giri.
 *Date: 23-02-2022
 *Time: 10:23:57
 */

/*
 *----------------------------------------------------------------
 *binary search performed on arranged or shorted array (in ascending order).
 *so if array is not sorted then we will sort the array using any algorithm.
 *here we will use bubble short algorithm to short the array.
 *----------------------------------------------------------------
 */

#ifndef MAX
#define MAX 10
#endif

#include <stdio.h>
int searchElement(int *array, int n);
void sortArrayInAscending(int *array);

/*main function*/
int main()
{
    int *array = (int *)calloc(MAX, sizeof(int));
    int desiredElement;
    for (int i = 0; i < MAX; i++)
    {
        printf("write element on index %d:\n", i);
        scanf("%d", &array[i]);
    }
    printf("\nWrite desiredElement to search using binary search algorithm:\n");
    scanf("%d", &desiredElement);

    int desiredIndex = searchElement(array, desiredElement);

    /*we will also print shorted array */
    puts("\n======SHORTED ARRAY ARE FOLLOWING======");
    for (int i = 0; i < MAX; i++)
        printf("[%d] = %d\t", i, array[i]);
    printf("\n\n");

    if (desiredIndex == -1)
        printf("==> Element %d is not available in array.\n", desiredElement);
    else
        printf("==> index of %d is %d\n", desiredElement, desiredIndex);

    return 0; // on success
}

/*Search passed element in array using binary search. And returns the index of the element. If element not found then return -1.*/
int searchElement(int *array, int n)
{
    /*because binary search algorithm implemented on sorted array. So, we will short the array in ascending order*/
    sortArrayInAscending(array);

    /*binary search*/
    int lower = 0;
    int upper = MAX - 1;
    int middle;

    while (lower <= upper)
    {
        middle = (upper + lower) / 2;

        if (n == array[middle])
            return middle;
        if (n < array[middle])
            upper = middle - 1;
        if (n > array[middle])
            lower = middle + 1;
    }
    return -1;
}

/*short the passed array in ascending order*/
void sortArrayInAscending(int *array)
{
    int temp; // to store the number temporarily
    for (int i = 0; i < MAX; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
